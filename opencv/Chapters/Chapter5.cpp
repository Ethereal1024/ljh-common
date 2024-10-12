#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

float w = 250, h = 350;
cv::Mat matrix, img_warp;

int main() {
    std::string path = "Resources/cards.jpg";
    cv::Mat img = cv::imread(path);

    cv::Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};
    cv::Point2f dist[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = cv::getPerspectiveTransform(src, dist);
    cv::warpPerspective(img, img_warp, matrix, cv::Size(w, h));

    for (auto p : src){
        cv::circle(img, p, 10, cv::Scalar(0, 69, 255), cv::FILLED);
    }

    cv::imshow("Image", img);
    cv::imshow("Image Warp", img_warp);
    cv::waitKey(0);
    return 0;
}