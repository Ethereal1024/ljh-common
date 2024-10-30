cmake_minimum_required(VERSION 3.0)
project(PCL_Viewer)

find_package(PCL 1.8 REQUIRED)
find_package(VTK REQUIRED COMPONENTS CommonCore)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_viewer main.cpp)

target_link_libraries(pcl_viewer ${VTK_LIBRARIES})
target_link_libraries(pcl_viewer ${PCL_LIBRARIES} pcl_common pcl_io pcl_visualization)
