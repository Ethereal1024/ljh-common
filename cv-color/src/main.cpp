#include "CubeColorDetector.hpp"

cv::Mat imgOriginal;

TargetColor blue{
    "blue",
    {97, 113},
    {98, 255},
    {0, 188},
    cv::Scalar(255, 0, 255)};

TargetColor yellow{
    "yellow",
    {21, 34},
    {120, 255},
    {92, 255},
    cv::Scalar(255, 255, 0)};

std::vector<TargetColor> targetColors = {blue, yellow};
CubeColorDetector detector(targetColors);

int main() {
    std::string path = "../image.png";
    cv::Mat img = cv::imread(path);
    detector.detect(img);

    cv::imshow("Detect result", img);
    cv::waitKey(0);
    return 0;
}