#include "founder_msgs/msg/founder_message.hpp"
#include "rclcpp/rclcpp.hpp"

class Tracker : public rclcpp::Node {
public:
    Tracker() : Node("tracker_node") {
        subscription_ = this->create_subscription<founder_msgs::msg::FounderMessage>(
            "tracker_params", 10,
            std::bind(&Tracker::recv_param, this, std::placeholders::_1));
    }

private:
    rclcpp::Subscription<founder_msgs::msg::FounderMessage>::SharedPtr subscription_;

    void recv_param(const founder_msgs::msg::FounderMessage::SharedPtr msg) {
        float ekf_xyz = msg->ekf.xyz;
        float ekf_yaw = msg->ekf.yaw;
        float ekf_r = msg->ekf.r;
        int vx = msg->vx;
        int vy = msg->vy;
        int vz = msg->vz;

        RCLCPP_INFO(this->get_logger(),
                    "参数已接收: xyz=%.3f, yaw=%.3f, r=%.3f, vx=%d, vy=%d, vz=%d",
                    ekf_xyz, ekf_yaw, ekf_r, vx, vy, vz);
    }
};


int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Tracker>());
    rclcpp::shutdown();
    return 0;
}