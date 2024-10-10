#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

int main(){
    cv::VideoCapture cap(0);
    cv::Mat img;

    while(true){
        cap.read(img);
        cv::imshow("Image", img);
        cv::waitKey(20);
    }
    return 0;
}