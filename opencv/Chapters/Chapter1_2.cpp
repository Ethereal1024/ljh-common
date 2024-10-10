#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(){
    std::string path = "../Resources/test_video.mp4";
    cv::VideoCapture cap(path);
    cv::Mat img;

    while(true){
        cap.read(img);
        cv::imshow("Image", img);
        cv::waitKey(20);
    }
    return 0;
}