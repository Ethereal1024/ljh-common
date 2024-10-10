#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(){
    // 获取空白图像
    cv::Mat img(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));
    // 绘制圆形
    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 69, 255), cv::FILLED);
    // 绘制矩形
    cv::rectangle(img, cv::Point(130, 226), cv::Point(382, 286), cv::Scalar(255, 255, 255), cv::FILLED);
    // 绘制线段
    cv::line(img, cv::Point(130, 296), cv::Point(382, 296), cv::Scalar(255, 255, 255), 2);
    // 书写文字
    cv::putText(
        img, "Hello, world!", cv::Point(137, 262), cv::QT_FONT_NORMAL, 1, cv::Scalar(0, 69, 255), 0);

    cv::imshow("Image", img);

    cv::waitKey(0);
    return 0;
}