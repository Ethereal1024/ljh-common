#include <condition_variable>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "image_transport/image_transport.hpp"
#include "rclcpp/rclcpp.hpp"
#include "reference_msgs/msg/reference.hpp"
#include "sensor_msgs/msg/image.hpp"

class Marker : public rclcpp::Node {
public:
    Marker()
        : Node("marker"), find_done_(false) {
        this->declare_parameter<int>("sideLen", 10);
        this->declare_parameter<int>("patternSize.x", 8);
        this->declare_parameter<int>("patternSize.y", 8);

        int x, y;
        this->get_parameter("sideLen", side_len_);
        this->get_parameter("patternSize.x", x);
        this->get_parameter("patternSize.y", y);
        pattern_size_ = cv::Size(x, y);

        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "image", 10, std::bind(&Marker::recev_callback, this, std::placeholders::_1));
        publisher_ = this->create_publisher<reference_msgs::msg::Reference>("references", 100);
    }

private:
    void recev_callback(sensor_msgs::msg::Image::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Image received.");
        cv::Mat img = cv_bridge::toCvCopy(msg, "bgr8")->image;
        cv::Mat imgGray;
        cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
        cv::imshow("imgGray", imgGray);

        std::thread findCorners(std::bind(&Marker::find_corners, this, imgGray));
        std::mutex mtx;
        std::unique_lock<std::mutex> lock(mtx);

        if (!count_done_.wait_for(lock, std::chrono::seconds(5), [this] { return find_done_.load(); })) {
            RCLCPP_ERROR(this->get_logger(), "Find corners timeout.");
            findCorners.join();
            return;
        }

        if (findCorners.joinable())
            findCorners.join();

        bool posted = post_reference();
        if (posted) {
            RCLCPP_INFO(this->get_logger(), "Reference published successfully, %d references published", (int)corners_.size());
        } else {
            RCLCPP_ERROR(this->get_logger(), "Reference publish failed.");
        }
    }

    bool post_reference() {
        if ((int)corners_.size() != pattern_size_.area())
            return false;
        else {
            for (int i = 0; i < pattern_size_.height; i++) {
                for (int j = 0; j < pattern_size_.width; j++) {
                    reference_msgs::msg::Reference refer;
                    int index = i * pattern_size_.width + j;
                    refer.vec_u.u = corners_[index].x;
                    refer.vec_u.v = corners_[index].y;
                    refer.vec_x.x_w = j * side_len_;
                    refer.vec_x.y_w = i * side_len_;
                    refer.vec_x.z_w = 0;
                    refer.delivering = 1;
                    publisher_->publish(refer);
                    if (index == (int)corners_.size() - 1) {
                        refer.delivering = 0;
                        publisher_->publish(refer);
                    }
                }
            }
        }
        return true;
    }

    void find_corners(cv::Mat imgGray) {
        bool patternFound = cv::findChessboardCorners(
            imgGray, pattern_size_, corners_,
            cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE + cv::CALIB_CB_FAST_CHECK);

        if (patternFound) {
            cv::cornerSubPix(
                imgGray, corners_, cv::Size(11, 11), cv::Size(-1, -1),
                cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));
        } else {
            RCLCPP_ERROR(this->get_logger(), "Could not find chessboard corners.");
        }
        find_done_ = true;
        count_done_.notify_one();
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    rclcpp::Publisher<reference_msgs::msg::Reference>::SharedPtr publisher_;
    int side_len_;
    cv::Size pattern_size_;  // 棋盘格角点个数
    std::vector<cv::Point2f> corners_;
    std::atomic<bool> find_done_;
    std::condition_variable count_done_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Marker>());
    rclcpp::shutdown();
    return 0;
}