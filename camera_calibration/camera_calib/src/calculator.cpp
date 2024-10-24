#include <Eigen/Dense>

#include "rclcpp/rclcpp.hpp"
#include "reference_msgs/msg/reference.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"

class Calculator : public rclcpp::Node {
public:
    Calculator() : Node("calculator") {
        mat_a_ = std::make_shared<Eigen::MatrixXd>();
        vec_p_ = std::make_shared<Eigen::VectorXd>();
        subscription_ = this->create_subscription<reference_msgs::msg::Reference>(
            "references", 100, std::bind(&Calculator::recev_callback, this, std::placeholders::_1));
        publisher_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("vector_p", 10);
    }

private:
    void recev_callback(const reference_msgs::msg::Reference::SharedPtr refer) {
        if (refer->delivering) {
            mat_a_->conservativeResize(mat_a_->rows() + 2, 12);
            mat_a_->block(mat_a_->rows() - 2, 0, 2, 12) << refer->vec_x.x_w, refer->vec_x.y_w, refer->vec_x.z_w, 1,
                0, 0, 0, 0,
                -refer->vec_u.u * refer->vec_x.x_w, -refer->vec_u.u * refer->vec_x.y_w,
                -refer->vec_u.u * refer->vec_x.z_w, -refer->vec_u.u,
                0, 0, 0, 0,
                refer->vec_x.x_w, refer->vec_x.y_w, refer->vec_x.z_w, 1,
                -refer->vec_u.v * refer->vec_x.x_w, -refer->vec_u.v * refer->vec_x.y_w,
                -refer->vec_u.v * refer->vec_x.z_w, -refer->vec_u.v;
        } else {
            solve_vec_p();
            auto message = std_msgs::msg::Float32MultiArray();
            message.data.resize(12);
            for (int i = 0; i < (int)message.data.size(); i++) {
                message.data[i] = (*vec_p_)[i];
            }
            publisher_->publish(message);
            RCLCPP_INFO(this->get_logger(), "Vector_p published successfully.");
            mat_a_ = std::make_shared<Eigen::MatrixXd>();
            vec_p_ = std::make_shared<Eigen::VectorXd>();
        }
    }

    void solve_vec_p() {
        Eigen::MatrixXd eigenMat = *(mat_a_) * mat_a_->transpose();
        Eigen::EigenSolver<Eigen::MatrixXd> solver(eigenMat);
        Eigen::VectorXd eigenvalues = solver.eigenvalues().real();
        Eigen::MatrixXd eigenvectors = solver.eigenvectors().real();

        float minEigenvalue = std::numeric_limits<float>::infinity();
        int minIndex = 0;

        for (int i = 0; i < (int)eigenvalues.size(); i++) {
            if (solver.eigenvalues()[i].imag() == 0 && eigenvalues[i] < minEigenvalue) {
                minEigenvalue = eigenvalues[i];
                minIndex = i;
            }
        }
        std::cout << "minEigenvalue: "  << minEigenvalue << std::endl;
        *vec_p_ = eigenvectors.col(minIndex);
    }
    rclcpp::Subscription<reference_msgs::msg::Reference>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr publisher_;
    std::shared_ptr<Eigen::MatrixXd> mat_a_;
    std::shared_ptr<Eigen::VectorXd> vec_p_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Calculator>());
    rclcpp::shutdown();
    return 0;
}