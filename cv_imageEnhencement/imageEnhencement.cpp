#include <cmath>
#include <exception>

#include "opencv2/opencv.hpp"

std::string path = "image.png";

void cubeEnhance(const cv::Mat& inputImg, cv::Mat& outputImg, const float weight) {
    if (weight < -1.5 || weight > 4) {
        throw std::invalid_argument("Weight must be between -1.5 and 4.");
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

int main() {
    try {
        cv::Mat img = cv::imread(path);
        cv::Mat result;

        cubeEnhance(img, result, 50);

        cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

        cv::imshow("Origin", img);
        cv::imshow("Result", result);
        cv::waitKey(0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
