#include "CubeColorDetector.hpp"

CubeColorDetector::CubeColorDetector(std::vector<TargetColor> inputColors)
: target_colors(inputColors){
}

void CubeColorDetector::find_color(const cv::Mat& inputImg, cv::Mat& outputImg, const TargetColor& target) {
    cv::Scalar lower(target.h.left, target.s.left, target.v.left);
    cv::Scalar upper(target.h.right, target.s.right, target.v.right);
    cv::inRange(inputImg, lower, upper, outputImg);
}

void CubeColorDetector::get_contours(const cv::Mat& inputImg, std::vector<Contour>& contours) {
    std::vector<Contour> contoursOriginal;
    std::vector<cv::Vec4i> tmpH;
    cv::findContours(inputImg, contoursOriginal, tmpH, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (auto contour : contoursOriginal) {
        float area = cv::contourArea(contour);
        if (area > 1000) {
            Contour newContour;
            float peri = cv::arcLength(contour, true);
            cv::approxPolyDP(contour, newContour, 0.02 * peri, true);
            contours.push_back(newContour);
        }
    }
}

void CubeColorDetector::draw_marker(const std::string& text, const cv::Rect& inputRect, const cv::Scalar& color, cv::Mat& targetImg) {
    float subRectWidth = inputRect.width / 4;
    float subRectHeight = inputRect.height / 20;
    float offset = subRectHeight / 2;

    cv::Point tl(inputRect.tl());
    cv::Point tr(inputRect.tl().x + inputRect.width, inputRect.tl().y);
    cv::Point bl(inputRect.tl().x, inputRect.tl().y + inputRect.height);
    cv::Point br(inputRect.br());

    cv::Size horizontalSize(subRectWidth, subRectHeight);
    cv::Size verticalSize(subRectHeight, subRectWidth);
    cv::Size squareSize(subRectHeight * 2, subRectHeight * 2);

    std::vector<cv::Rect> subRects(8);
    subRects[0] = cv::Rect(cv::Point(tl.x - offset, tl.y - offset), horizontalSize);
    subRects[1] = cv::Rect(cv::Point(tl.x - offset, tl.y - offset), verticalSize);
    subRects[2] = cv::Rect(cv::Point(bl.x - offset, bl.y - offset), horizontalSize);
    subRects[3] = cv::Rect(cv::Point(bl.x - offset, bl.y - subRectWidth + offset), verticalSize);
    subRects[4] = cv::Rect(cv::Point(tr.x - subRectWidth + offset, tr.y - offset), horizontalSize);
    subRects[5] = cv::Rect(cv::Point(tr.x - offset, tr.y - offset), verticalSize);
    subRects[6] = cv::Rect(cv::Point(br.x - subRectWidth + offset, br.y - offset), horizontalSize);
    subRects[7] = cv::Rect(cv::Point(br.x - offset, br.y - subRectWidth + offset), verticalSize);

    for (auto subRect : subRects) {
        cv::rectangle(targetImg, subRect, color, cv::FILLED);
    }

    cv::putText(targetImg,
                text,
                cv::Point(tl.x, tl.y + inputRect.height / 2),
                cv::FONT_ITALIC,
                0.5,
                color,
                1);
}

void CubeColorDetector::detect_color(cv::Mat& targetImg_, const TargetColor& color_) {
    cv::Mat imgHSV, targetColorRange;
    cv::cvtColor(targetImg_, imgHSV, cv::COLOR_BGR2HSV);

    find_color(imgHSV, targetColorRange, color_);

    std::vector<Contour> targetColorContours;
    get_contours(targetColorRange, targetColorContours);

    for (auto contour : targetColorContours) {
        cv::Rect boundRect = cv::boundingRect(contour);
        draw_marker(color_.name, boundRect, color_.mark_color, targetImg_);
    }
}

void CubeColorDetector::add_target_color(TargetColor targetColor_) {
    target_colors.push_back(targetColor_);
}

void CubeColorDetector::detect(cv::Mat& img_){
    for(auto color : target_colors){
        detect_color(img_, color);
    }
}

void adjustWindow(cv::Mat inputImg){
    cv::Mat imgHSV, mask;
    cv::cvtColor(inputImg, imgHSV, cv::COLOR_BGR2HSV);
    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 255, vmax = 255;
    cv::namedWindow("Trackbars", (640, 200));
    cv::createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    cv::createTrackbar("Sat Min", "Trackbars", &smin, 255);
    cv::createTrackbar("Val Min", "Trackbars", &vmin, 255);
    cv::createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    cv::createTrackbar("Sat Max", "Trackbars", &smax, 255);
    cv::createTrackbar("Val Max", "Trackbars", &vmax, 255);
    while (true) {
        cv::Scalar lower(hmin, smin, vmin);
        cv::Scalar upper(hmax, smax, vmax);
        cv::inRange(imgHSV, lower, upper, mask);
        cv::imshow("Image", inputImg);
        cv::imshow("Mask", mask);
        cv::waitKey(1);
    }
}