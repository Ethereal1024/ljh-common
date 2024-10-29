#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "cv_bridge/cv_bridge.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

std::string modelPath = "src/nn_armor_plate_identify/YOLOv8_armor_identify.onnx";

const cv::Size input_shape = {256, 256};
const std::vector<std::string> names = {"B1", "B2", "B3", "B4", "B5", "B7", "R1", "R2", "R3", "R4", "R5", "R7"};
const std::vector<cv::Scalar> colors = {
    {255, 0, 255},
    {255, 0, 255},
    {255, 0, 255},
    {255, 0, 255},
    {255, 0, 255},
    {255, 0, 255},
    {0, 255, 0},
    {0, 255, 0},
    {0, 255, 0},
    {0, 255, 0},
    {0, 255, 0},
    {0, 255, 0}};

cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 1462.3697, 0, 398.59394,
                        0, 1469.68385, 110.68997,
                        0, 0, 1);

std::vector<cv::Point3f> objectPoints = {
    {4, 4, 0}, {4, -4, 0}, {-4, -4, 0}, {-4, 4, 0}};

cv::Mat distCoeffs = (cv::Mat_<double>(5, 1) << 0.003518, -0.311778, -0.016581, 0.023682, 0.0000);

class NNLocator : public rclcpp::Node {
public:
    NNLocator() : Node("nn_locator") {
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
            "image", 10, std::bind(&NNLocator::recev_callback, this, std::placeholders::_1));
        model_init();
    }

private:
    void recev_callback(sensor_msgs::msg::Image::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Image received.");
        cv::Mat img = cv_bridge::toCvCopy(msg, "bgr8")->image;
        float scale_x = (float)img.cols / (float)input_shape.width;
        float scale_y = (float)img.rows / (float)input_shape.height;
        // 图像预处理
        // TODO:试验是否归一化
        cv::Mat inputBlob = cv::dnn::blobFromImage(img, 1.0 / 255, input_shape, cv::Scalar(0, 0, 0), true, false);

        model_.setInput(inputBlob);
        cv::Mat detection_3d = model_.forward();

        cv::Mat detection = detection_3d.reshape(1, detection_3d.size[1]);

        std::vector<cv::Rect> boxes;  // 候选检测框
        std::vector<float> confs;     // 候选置信度
        std::vector<int> classIdcs;
        for (int i = 0; i < detection.cols; i++) {
            // 找到最大的概率值及其对应下标
            float confidence = 0, classIdx = 0;
            for (int j = 4; j < detection.rows; j++) {
                float cur_prop = detection.at<float>(j, i);
                if (cur_prop > confidence) {
                    confidence = cur_prop;
                    classIdx = j - 4;
                }
            }

            if (confidence > 0.5) {
                float _width = detection.at<float>(2, i);
                float _height = detection.at<float>(3, i);
                int x = static_cast<int>((detection.at<float>(0, i) - _width * 0.5) * scale_x);
                int y = static_cast<int>((detection.at<float>(1, i) - _height * 0.5) * scale_y);
                int width = static_cast<int>(_width * scale_x);
                int height = static_cast<int>(_height * scale_y);
                boxes.push_back(cv::Rect(x, y, width, height));
                confs.push_back(confidence);
                classIdcs.push_back(classIdx);
            }
        }

        std::vector<int> indices;
        cv::dnn::NMSBoxes(boxes, confs, 0.5, 0.4, indices);

        for (int idx : indices) {
            int classIdx = classIdcs[idx];
            std::stringstream ss;
            float confidence = confs[idx];
            ss << names[classIdx] << " (" << std::fixed << std::setprecision(2) << confidence * 100 << "%)";
            draw_marker(ss.str(), boxes[idx], colors[classIdx], img);
            std::vector<cv::Point2f> measurePoints = {
                boxes[idx].tl() + cv::Point(boxes[idx].width, 0), 
                boxes[idx].tl(), 
                boxes[idx].br() - cv::Point(boxes[idx].width, 0), 
                boxes[idx].br()
            };
            measure_distance(measurePoints);
        }

        // 调试时的效果检验代码
        // cv::imshow("result", img);
        // cv::imwrite("output_imgs/output.png", img);
        // cv::waitKey(0);
    }

    void measure_distance(const std::vector<cv::Point2f>& imagePoints){
        cv::Mat rvec, tvec;
        bool success = cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec);

        double distance = cv::norm(tvec);
        RCLCPP_INFO(this->get_logger(), "Distance: %.3f m", 0.01 * distance);
    }

    void model_init() {
        model_ = cv::dnn::readNetFromONNX(modelPath);
        model_.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
        model_.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
    }

    void draw_marker(const std::string& text, const cv::Rect& inputRect, const cv::Scalar& color, cv::Mat& targetImg) {
        float subRectWidth = inputRect.width / 4;
        float subRectHeight = inputRect.height / 20;
        float offset = subRectHeight / 2;

        cv::Point tl(inputRect.tl());
        cv::Point tr(inputRect.tl().x + inputRect.width, inputRect.tl().y);
        cv::Point bl(inputRect.tl().x, inputRect.tl().y + inputRect.height);
        cv::Point br(inputRect.br());

        cv::Size horizontalSize(subRectWidth, subRectHeight);
        cv::Size verticalSize(subRectHeight, subRectWidth);
        cv::Size squareSize(subRectHeight * 2, subRectHeight * 2);

        std::vector<cv::Rect> subRects(8);
        subRects[0] = cv::Rect(cv::Point(tl.x - offset, tl.y - offset), horizontalSize);
        subRects[1] = cv::Rect(cv::Point(tl.x - offset, tl.y - offset), verticalSize);
        subRects[2] = cv::Rect(cv::Point(bl.x - offset, bl.y - offset), horizontalSize);
        subRects[3] = cv::Rect(cv::Point(bl.x - offset, bl.y - subRectWidth + offset), verticalSize);
        subRects[4] = cv::Rect(cv::Point(tr.x - subRectWidth + offset, tr.y - offset), horizontalSize);
        subRects[5] = cv::Rect(cv::Point(tr.x - offset, tr.y - offset), verticalSize);
        subRects[6] = cv::Rect(cv::Point(br.x - subRectWidth + offset, br.y - offset), horizontalSize);
        subRects[7] = cv::Rect(cv::Point(br.x - offset, br.y - subRectWidth + offset), verticalSize);

        for (auto subRect : subRects) {
            cv::rectangle(targetImg, subRect, color, cv::FILLED);
        }

        cv::rectangle(targetImg, 
        cv::Rect(cv::Point(tl.x - offset, tl.y - offset - 20), cv::Point(tl.x + text.size() * 10, tl.y - offset)), 
        color, cv::FILLED);

        cv::putText(targetImg,
                    text,
                    cv::Point(tl.x, tl.y - offset - 6),
                    cv::FONT_ITALIC,
                    0.5,
                    cv::Scalar(20, 20, 20),
                    1);
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
    cv::dnn::Net model_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NNLocator>());
    rclcpp::shutdown();
    return 0;
}