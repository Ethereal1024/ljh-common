#ifndef CUBEDETECTOR_HPP
#define CUBEDETECTOR_HPP

#include <iostream>

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

typedef struct _range {
        int left;
        int right;
    } Range;

typedef struct _target {
        std::string name;
        Range h;
        Range s;
        Range v;
        cv::Scalar mark_color;
    } TargetColor;

void adjustWindow(const cv::Mat inputImg);

class CubeColorDetector {
private:
    std::vector<TargetColor> target_colors;
    typedef std::vector<cv::Point> Contour;
    void find_color(const cv::Mat&, cv::Mat&, const TargetColor&);
    void get_contours(const cv::Mat&, std::vector<Contour>&);
    void draw_marker(const std::string&, const cv::Rect&, const cv::Scalar&, cv::Mat&);
    void detect_color(cv::Mat&, const TargetColor&);
public:
    CubeColorDetector(std::vector<TargetColor>);
    void add_target_color(TargetColor);
    void detect(cv::Mat&);
};

#endif