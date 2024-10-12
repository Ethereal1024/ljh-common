cmake_minimum_required(VERSION 3.8)

project(cube_color_detect)

include_directories(includes)
include_directories("E:/Program Files (x86)/Dev-Cpp/MinGW64/include")

add_executable(cube_color_detect ./tools/CubeColorDetector.cpp ./src/main.cpp)

target_link_libraries(cube_color_detect 
    opencv_core452
    opencv_imgcodecs452
    opencv_imgproc452
    opencv_calib3d452
    opencv_dnn452
    opencv_features2d452
    opencv_flann452
    opencv_gapi452
    opencv_highgui452
    opencv_ml452
    opencv_objdetect452
    opencv_photo452
    opencv_stitching452
    opencv_video452
    opencv_videoio452
)
