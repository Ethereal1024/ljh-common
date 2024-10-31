cmake_minimum_required(VERSION 3.8)
project(coordinate_conversion)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

include_directories(${tf2_INCLUDE_DIRS})
include_directories(${tf2_ros_INCLUDE_DIRS})

add_executable(inte_locator src/inte_locator.cpp)
add_executable(converter src/converter.cpp)

ament_target_dependencies(inte_locator rclcpp sensor_msgs cv_bridge)
ament_target_dependencies(converter rclcpp tf2 tf2_ros)

target_link_libraries(inte_locator ${OpenCV_LIBS})
target_link_libraries(converter ${OpenCV_LIBS} ${tf2_LIBRARIES} ${tf2_ros_LIBRARIES})

install(TARGETS
  inte_locator
  converter
  DESTINATION lib/${PROJECT_NAME})

ament_package()
