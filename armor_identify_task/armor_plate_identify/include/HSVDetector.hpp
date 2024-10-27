#ifndef HSVDETECTOR_HPP
#define HSVDETECTOR_HPP

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
    } Target;

void adjustWindow(const cv::Mat inputImg);

typedef std::vector<cv::Point> Contour;

class HSVDetector {
private:
    int min_size_;
    std::vector<Target> targets;
    std::vector<Contour> target_contours_;
    void find_hsv(const cv::Mat&, cv::Mat&, const Target&);
    void get_contours(const cv::Mat&, std::vector<Contour>&);
    void detect_target(const cv::Mat&, const Target&, cv::Mat&);
public:
    HSVDetector(std::vector<Target>, const int&);
    std::vector<Contour> get_target_contours();
    void add_target(Target);
    void detect(const cv::Mat&, cv::Mat&);
    void draw_marker(const std::string&, const Contour&, const cv::Scalar&, cv::Mat&);
};

#endif