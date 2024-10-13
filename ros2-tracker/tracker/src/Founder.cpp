#include "founder_msgs/msg/founder_message.hpp"
#include "rclcpp/rclcpp.hpp"

class Founder : public rclcpp::Node {
public:
    Founder() : Node("founder_node") {
        init_param();
        publisher_ = this->create_publisher<founder_msgs::msg::FounderMessage>("tracker_params", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&Founder::timer_call_back, this));
    }

private:
    float ekf_xyz_, ekf_yaw_, ekf_r_;
    int vx_, vy_, vz_;

    rclcpp::Publisher<founder_msgs::msg::FounderMessage>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void timer_call_back() {
        auto message = founder_msgs::msg::FounderMessage();
        message.ekf.xyz = ekf_xyz_;
        message.ekf.yaw = ekf_yaw_;
        message.ekf.r = ekf_r_;
        message.vx = vx_;
        message.vy = vy_;
        message.vz = vz_;
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "参数已发布.");
    }

    void init_param() {
        this->declare_parameter("ekf.xyz", 0.0);
        this->declare_parameter("ekf.yaw", 0.0);
        this->declare_parameter("ekf.r", 0.0);
        this->declare_parameter("vx", 0);
        this->declare_parameter("vy", 0);
        this->declare_parameter("vz", 0);

        this->get_parameter("ekf.xyz", ekf_xyz_);
        this->get_parameter("ekf.yaw", ekf_yaw_);
        this->get_parameter("ekf.r", ekf_r_);
        this->get_parameter("vx", vx_);
        this->get_parameter("vy", vy_);
        this->get_parameter("vz", vz_);

        RCLCPP_INFO(this->get_logger(),
                    "参数已加载: xyz=%.3f, yaw=%.3f, r=%.3f, vx=%d, vy=%d, vz=%d",
                    ekf_xyz_, ekf_yaw_, ekf_r_, vx_, vy_, vz_);
    }
};


int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Founder>());
    rclcpp::shutdown();
    return 0;
}