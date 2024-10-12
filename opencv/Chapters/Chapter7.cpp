#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat img_gray, img_blur, img_canny, img_dil, img_erode;

void getContours(cv::Mat input_img, cv::Mat output_img){
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(input_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> con_poly(contours.size());
    std::vector<cv::Rect> boundRect(contours.size());
    std::string obj_type;
    for (int i = 0; i < contours.size(); i++){
        int area = contourArea(contours[i]);
        if(area > 1000){
            float peri = cv::arcLength(contours[i], true);
            cv::approxPolyDP(contours[i], con_poly[i], 0.02 * peri, true);
            cv::drawContours(output_img, con_poly, i, cv::Scalar(255, 0, 255), 2);
            boundRect[i] = cv::boundingRect(con_poly[i]);
            
            int obj_cor = (int)con_poly[i].size();
            if(obj_cor == 3){
                obj_type = "Triangle";
            } else if(obj_cor == 4){
                obj_type = "Rectangle";
                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
                if(aspRatio > 0.95 && aspRatio < 1.05) obj_type = "Square";
            } else if(obj_cor > 4){
                obj_type = "Circle";
            }

            cv::rectangle(output_img, boundRect[i], cv::Scalar(255, 255, 0), 3);
            cv::putText(
                output_img, 
                obj_type, 
                {boundRect[i].x, boundRect[i].y - 5}, 
                cv::FONT_HERSHEY_PLAIN, 
                1, 
                cv::Scalar(180, 0, 255),
                0);
        }
    }
}


int main(){
    std::string path = "../Resources/shapes.png";
    cv::Mat img = cv::imread(path);

    // 图像预处理
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);  // 黑白化图像
    cv::GaussianBlur(img_gray, img_blur, cv::Size(3, 3), 3);  // 高斯模糊
    cv::Canny(img_blur, img_canny, 80, 125);  // 检测边缘

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(img_canny, img_dil, kernel);  // 扩散

    getContours(img_dil, img);

    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}