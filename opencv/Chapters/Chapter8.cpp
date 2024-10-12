#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main(){
    std::string path = "../Resources/test.png";
    cv::Mat img = cv::imread(path);

    cv::CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    if(faceCascade.empty())
        std::cout << "XML file not loaded." << std::endl;

    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);
    
    for(auto face : faces){
        cv::rectangle(img, face, cv::Scalar(69, 50, 213), 5);
    }

    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}