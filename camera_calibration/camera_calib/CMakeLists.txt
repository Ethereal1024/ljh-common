cmake_minimum_required(VERSION 3.8)
project(camera_calib)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(reference_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(image_transport REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})

add_executable(captor src/captor.cpp)
add_executable(marker src/marker.cpp)
add_executable(calculator src/calculator.cpp)
add_executable(decomposer src/decomposer.cpp)

target_link_libraries(marker ${OpenCV_LIBRARIES})

ament_target_dependencies(captor rclcpp std_msgs sensor_msgs cv_bridge)
ament_target_dependencies(marker rclcpp std_msgs sensor_msgs cv_bridge reference_msgs image_transport)
ament_target_dependencies(calculator rclcpp std_msgs reference_msgs)
ament_target_dependencies(decomposer rclcpp std_msgs reference_msgs)


install(TARGETS
  captor
  marker
  calculator
  decomposer
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)


ament_package()