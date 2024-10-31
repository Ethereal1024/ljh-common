#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Vector3.h>

#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32_multi_array.hpp"

cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 1462.3697, 0, 398.59394,
                        0, 1469.68385, 110.68997,
                        0, 0, 1);

cv::Mat distCoeffs = (cv::Mat_<double>(5, 1) << 0.003518, -0.311778, -0.016581, 0.023682, 0.0000);

tf2::Vector3 translation(0.08, 0.0, 0.05);
float rotationParams[3] = {2 / 57.3, 60 / 57.3, 20 / 57.3};

class Converter : public rclcpp::Node {
public:
    Converter() : Node("converter") {
        subscriber_ = this->create_subscription<std_msgs::msg::Int32MultiArray>(
            "pixel_coordinate", 10, std::bind(&Converter::recev_callback, this, std::placeholders::_1));
        rotation_.setRPY(rotationParams[0], rotationParams[1], rotationParams[2]);
    }

private:
    void recev_callback(const std_msgs::msg::Int32MultiArray::SharedPtr msg) {
        if (msg->data.size() != 3) {
            RCLCPP_ERROR(
                this->get_logger(), "Parameter number error. (Expected 3, received %ld)", msg->data.size());
            return;
        } else {
            double u = static_cast<double>(msg->data[0]);
            double v = static_cast<double>(msg->data[1]);
            double d = static_cast<double>(msg->data[2]);
            // RCLCPP_INFO(this->get_logger(), "Successfully received pixel coordinate: (%f , %f).", u, v);
            cv::Point2d pixelCoordinate(u, v);
            cv::Point3d oodmCoordinate = get_oodm_from_pixel(pixelCoordinate, d);
            double x_w = oodmCoordinate.x;
            double y_w = oodmCoordinate.y;
            double z_w = oodmCoordinate.z;
            RCLCPP_INFO(
                this->get_logger(), "World coordinate: (%f, %f, %f).", x_w, y_w, z_w);
        }
    }

    cv::Point3d get_oodm_from_pixel(const cv::Point2d& pixelPoint, const double distance) {
        std::vector<cv::Point2d> pixelPoints = {pixelPoint};
        std::vector<cv::Point2d> objectPoints;
        cv::undistortPoints(pixelPoints, objectPoints, cameraMatrix, distCoeffs);
        tf2::Vector3 cameraVector(objectPoints[0].x * distance, objectPoints[0].y * distance, distance);
        tf2::Transform cameraToOodmTransform(rotation_, translation);
        tf2::Vector3 oodmVector = cameraToOodmTransform * cameraVector;
        cv::Point3d oodmPoint(oodmVector.x(), oodmVector.y(), oodmVector.z());
        return oodmPoint;
    }
    rclcpp::Subscription<std_msgs::msg::Int32MultiArray>::SharedPtr subscriber_;
    tf2::Quaternion rotation_;
};

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Converter>());
    rclcpp::shutdown();
    return 0;
}
