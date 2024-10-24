#include <Eigen/Dense>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"

class Decomposer : public rclcpp::Node {
public:
    Decomposer() : Node("decomposer"), mat_p_(3, 4) {
        subscription_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(
            "vector_p", 10, std::bind(&Decomposer::recev_callback, this, std::placeholders::_1));
    }

private:
    void recev_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Vector_p received.");
        for (int i = 0; i < (int)msg->data.size(); i++) {
            mat_p_(i / 4, i % 4) = msg->data[i];
        }
        upgrade_kr();
        upgrade_t();
        Eigen::MatrixXd mat_int_ = get_mat_int();
        
        std::stringstream intMatStr;
        intMatStr << "\nIntrinsics matrix:\n"
                  << mat_int_ << "\n";
        RCLCPP_INFO(this->get_logger(), intMatStr.str().c_str());

        std::stringstream extMatStr;
        Eigen::MatrixXd mat_ext_ = get_mat_ext();
        extMatStr << "\nExtrinsics matrix:\n"
                  << mat_ext_;
        RCLCPP_INFO(this->get_logger(), extMatStr.str().c_str());
    }

    void upgrade_kr(){
        Eigen::MatrixXd sub_mat_p_left = mat_p_.block<3, 3>(0, 0);
        Eigen::HouseholderQR<Eigen::MatrixXd> qr(sub_mat_p_left);
        mat_r_ = qr.householderQ();
        mat_k_ = qr.matrixQR().triangularView<Eigen::Upper>();
    }

    void upgrade_t(){
        Eigen::MatrixXd sub_mat_p_right = mat_p_.block<3, 1>(0, 3);
        if(!mat_k_.rows())
            upgrade_kr();
        mat_t_ = mat_k_.inverse() * sub_mat_p_right;
    }

    Eigen::MatrixXd get_mat_int(){
        if(!mat_k_.rows())
            upgrade_kr();
        Eigen::MatrixXd mat_int(3, 4);
        mat_int << mat_k_, Eigen::MatrixXd::Zero(3, 1);
        return mat_int;
    }

    Eigen::MatrixXd get_mat_ext(){
        if(!mat_t_.rows())
            upgrade_t();
        Eigen::MatrixXd mat_ext(4, 4);
        mat_ext.block(0, 0, 3, 3) = mat_r_;
        mat_ext.block(0, 3, 3, 1) = mat_t_;
        mat_ext.block(3, 0, 1, 3) = Eigen::MatrixXd::Zero(1, 3);
        mat_ext(3, 3) = 1;
        return mat_ext;
    }

    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr subscription_;
    Eigen::MatrixXd mat_p_, mat_k_, mat_r_, mat_t_;
};

int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Decomposer>());
    rclcpp::shutdown();
    return 0;
}