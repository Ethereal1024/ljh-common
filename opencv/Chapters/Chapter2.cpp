#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(){
    std::string path = "../Resources/test.png";
    cv::Mat img = cv::imread(path);
    cv::Mat img_gray, img_blur, img_canny, img_dil, img_erode;

    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);  // 黑白化图像
    cv::GaussianBlur(img, img_blur, cv::Size(5, 5), 5);  // 高斯模糊
    cv::Canny(img_blur, img_canny, 50, 150);  // 检测边缘

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));  // 定义卷积核大小
    cv::dilate(img_canny, img_dil, kernel);  // 扩散
    cv::erode(img_dil, img_erode, kernel);  // 腐蚀

    cv::imshow("Image", img);
    cv::imshow("Image Gray", img_gray);
    cv::imshow("Image Blur", img_blur);
    cv::imshow("Image Canny", img_canny);
    cv::imshow("Image Dilation", img_dil);
    cv::imshow("Image Erode", img_erode);
    cv::waitKey(0);
}