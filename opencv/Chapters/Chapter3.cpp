#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(){
    std::string path = "../Resources/test.png";
    cv::Mat img = cv::imread(path);
    cv::Mat img_resize, img_crop;

    cv::resize(img, img_resize, cv::Size(), 0.5, 0.5);  // 改变大小

    cv::Rect roi(200, 100, 300, 300);  // 定义裁剪矩形
    img_crop = img(roi);  // 裁剪图像

    cv::imshow("Image", img);
    cv::imshow("Image Resize", img_resize);
    cv::imshow("Image Crop", img_crop);

    cv::waitKey(0);
    return 0;
}