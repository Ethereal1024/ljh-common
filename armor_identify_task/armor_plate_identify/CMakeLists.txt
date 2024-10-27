cmake_minimum_required(VERSION 3.8)
project(armor_plate_identify)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(ament_cmake REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(locator src/locator.cpp src/HSVDetector.cpp)
ament_target_dependencies(locator rclcpp sensor_msgs cv_bridge)

target_link_libraries(locator ${OpenCV_LIBS})

install(TARGETS
  locator
  DESTINATION lib/${PROJECT_NAME}
)



ament_package()
