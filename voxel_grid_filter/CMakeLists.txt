cmake_minimum_required(VERSION 3.0)
project(PCL_Filtering)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_filtering main.cpp)
target_link_libraries(pcl_filtering ${PCL_LIBRARIES} pcl_common pcl_io pcl_filters)