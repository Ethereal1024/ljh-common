#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <dirent.h>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

class Captor : public rclcpp::Node {
public:
    Captor(std::string rootPath) 
    : Node("captor"), root_path_(rootPath){
        paths_init();
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("image", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000), std::bind(&Captor::timer_callback, this));
        bridge_ = std::make_shared<cv_bridge::CvImage>();
    }

private:
    void paths_init() {
        if (root_path_ == "0") {
            return;
        } else {
            DIR *dir = opendir(root_path_.c_str());
            if(dir == nullptr){
                std::string error = "Failed to open directory: " + root_path_;
                RCLCPP_ERROR(this->get_logger(), error.c_str());
                return;
            }
            struct dirent *entry;
            while((entry = readdir(dir)) != nullptr){
                std::string file_name = entry->d_name;
                if (file_name.size() >= 4 && 
                    (file_name.substr(file_name.size() - 4) == ".jpg" || 
                    file_name.substr(file_name.size() - 4) == ".png")){
                    img_paths_.push(root_path_ + "/" + file_name);
                }
            }
            closedir(dir);
        }
    }

    void timer_callback(){
        if (root_path_ == "0"){
            return;  // 后续按需求添加调用摄像机的代码
        } else {
            if(img_paths_.empty())
                return;
            std::string path = img_paths_.front();
            img_paths_.pop();
            cv::Mat img = cv::imread(path);
            if(img.empty()){
                std::string error = "Failed to load image: " + path;
                RCLCPP_ERROR(this->get_logger(), error.c_str());
                return;
            }

            bridge_->header.stamp = this->get_clock()->now();
            bridge_->encoding = "bgr8";
            bridge_->image = img;
            auto img_msg = bridge_->toImageMsg();
            publisher_->publish(*img_msg);
            std::string publish_announcement = "Image: " + path + " published.";
            RCLCPP_INFO(this->get_logger(), publish_announcement.c_str());
        }
    }

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<cv_bridge::CvImage> bridge_;

    std::string root_path_;
    std::queue<std::string> img_paths_;
};

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Captor>("./test_images"));
    rclcpp::shutdown();
    return 0;
}