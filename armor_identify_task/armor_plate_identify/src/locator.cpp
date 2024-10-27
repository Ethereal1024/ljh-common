#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

#include "HSVDetector.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

Target number1{
    "Number",
    {124, 152},
    {56, 87},
    {235, 255},
    cv::Scalar(255, 0, 255)};

Target number2{
    "Number",
    {33, 107},
    {0, 21},
    {5, 255},
    cv::Scalar(255, 0, 255)};

Target glare1{
    "Glare",
    {0, 179},
    {0, 20},
    {200, 255},
    cv::Scalar(255, 255, 0)};

Target glare2{
    "Glare",
    {0, 179},
    {0, 20},
    {200, 255},
    cv::Scalar(255, 255, 0)};

Target color1{
    "Color",
    {0, 15},
    {0, 255},
    {0, 255},
    cv::Scalar(0, 255, 255)};

Target color2{
    "Color",
    {54, 94},
    {34, 124},
    {0, 255},
    cv::Scalar(0, 255, 255)};

std::vector<Target> redTarget = {number1, glare1, color1};
std::vector<Target> blueTarget = {number2, glare2, color2};

cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 1462.3697, 0, 398.59394,
                        0, 1469.68385, 110.68997,
                        0, 0, 1);

std::vector<cv::Point3f> objectPoints = {
    {4, 2, 0}, {4, -2, 0}, {-4, -2, 0}, {-4, 2, 0}};

cv::Mat distCoeffs = (cv::Mat_<double>(5, 1) << 0.003518, -0.311778, -0.016581, 0.023682, 0.0000);

class Locator : public rclcpp::Node {
public:
    Locator(const std::vector<Target>& targetElems)
        : Node("locator"), num_(targetElems[0]), glare_(targetElems[1]), color_(targetElems[2]) {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "image", 10, std::bind(&Locator::recev_callback, this, std::placeholders::_1));
    }

private:
    void recev_callback(sensor_msgs::msg::Image::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Image received.");
        img_ = cv_bridge::toCvCopy(msg, "bgr8")->image;
        processing();
    }

    void processing() {
        cv::Mat imgPlaceHolder = cv::Mat::zeros(img_.rows, img_.cols, CV_8UC3);

        HSVDetector numDetector({num_}, 100);
        numDetector.detect(img_, imgPlaceHolder);

        cv::Mat contrustImg;
        cubeEnhance(img_, contrustImg, -0.8);
        HSVDetector glareDetector({glare_}, 10);
        glareDetector.detect(contrustImg, imgPlaceHolder);

        cv::Mat detailImg;
        cubeEnhance(img_, detailImg, 1.0);
        HSVDetector colorDetector({color_}, 10);
        colorDetector.detect(detailImg, imgPlaceHolder);

        std::vector<Contour> lightBars;

        // 取和颜色轮廓有重叠的强光轮廓作为候选灯条区
        for (auto glareContour : glareDetector.get_target_contours()) {
            for (auto colorContour : colorDetector.get_target_contours()) {
                cv::Rect glareRect = cv::boundingRect(glareContour);
                cv::Rect colorRect = cv::boundingRect(colorContour);
                if ((glareRect & colorRect).area() > 0) {
                    lightBars.push_back(glareContour);
                }
            }
        }

        // 找到锚点最多的轮廓作为数字区域
        std::vector<Contour> numContours = numDetector.get_target_contours();
        if(numContours.empty()){
            RCLCPP_ERROR(this->get_logger(), "Targer not found.");
            return;
        }
        int maxPointNum = 0, maxIdx = 0;
        if (numContours.size() > 1) {
            for (int i = 0; i < (int)numContours.size(); i++) {
                if ((int)numContours[i].size() > maxPointNum) {
                    maxPointNum = (int)numContours[i].size();
                    maxIdx = i;
                }
            }
        }

        colorDetector.draw_marker("Number", numContours[maxIdx], cv::Scalar(255, 0, 255), img_);

        // 找到和数字区域最近的两个候选灯条区作为目标灯条区域
        while (lightBars.size() > 2) {
            cv::Rect numRect = cv::boundingRect(numContours[maxIdx]);
            cv::Point numPos = cv::Point((numRect.tl().x + numRect.br().x) / 2, (numRect.tl().y + numRect.br().y) / 2);
            int maxDist = 0, maxIndex = 0;
            for (int i = 0; i < (int)lightBars.size(); i++) {
                cv::Rect barRect = cv::boundingRect(lightBars[i]);
                cv::Point barPos = cv::Point((barRect.tl().x + barRect.br().x) / 2, (barRect.tl().y + barRect.br().y) / 2);
                int dist = cv::norm(numPos - barPos);
                if (dist > maxDist) {
                    maxDist = dist;
                    maxIndex = i;
                }
            }
            lightBars.erase(lightBars.begin() + maxIndex);
        }

        for (auto contour : lightBars) {
            colorDetector.draw_marker("Light Bar", contour, cv::Scalar(0, 255, 0), img_);
        }

        cv::Rect barRectLeft, barRectRight;
        cv::Rect barRect1 = cv::boundingRect(lightBars[0]);
        cv::Rect barRect2 = cv::boundingRect(lightBars[1]);

        if(barRect1.tl().x < barRect2.tl().x){
            barRectLeft = barRect1;
            barRectRight = barRect2;
        } else {
            barRectLeft = barRect2;
            barRectRight = barRect1;
        }
        std::vector<cv::Point2f> imagePoints= {
            cv::Point2f(barRectRight.tl() + cv::Point(barRectRight.width, 0)), cv::Point2f(barRectLeft.tl()),
            cv::Point2f(barRectLeft.br() - cv::Point(barRectLeft.width, 0)), cv::Point2f(barRectRight.br())};

        cv::Mat rvec, tvec;
        bool success = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);

        double distance = cv::norm(tvec);
        RCLCPP_INFO(this->get_logger(), "Distance: %.3f m", 0.01 * distance);

        // cv::imshow("Detect result", img_);
        // cv::imwrite("output_imgs/output.png", img_);
        // cv::waitKey(0);
    }

    // 立方变换
    void cubeEnhance(const cv::Mat& inputImg, cv::Mat& outputImg, const float weight) {
        if (weight < -1.5 || weight > 1.5) {
            throw std::invalid_argument("Weight must be between -1.5 and 1.5.");
        }

        if (inputImg.empty()) {
            throw std::runtime_error("Input image is empty.");
        }

        cv::Mat imgFloat;
        inputImg.convertTo(imgFloat, CV_32FC3);
        cv::Mat imgNormal = (imgFloat - 128) / 128;
        cv::Mat imgNormalCube;
        if (weight > 0)
            cv::pow(imgNormal, 3, imgNormalCube);
        else
            cv::pow(imgNormal, 1.0 / 3.0, imgNormalCube);

        float k = std::abs(weight);
        imgNormal = k * imgNormalCube + (1 - k) * imgNormal;
        outputImg = imgNormal;
        outputImg = outputImg * 128 + 128;
        outputImg.convertTo(outputImg, CV_8UC3);
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    cv::Mat img_;
    Target num_;
    Target glare_;
    Target color_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Locator>(redTarget));
    rclcpp::shutdown();
    return 0;
}