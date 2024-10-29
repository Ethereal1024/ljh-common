cmake_minimum_required(VERSION 3.8)
project(nn_armor_plate_identify)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(nn_locator src/nn_locator.cpp)
ament_target_dependencies(nn_locator rclcpp sensor_msgs cv_bridge)

target_link_libraries(nn_locator ${OpenCV_LIBS})

install(TARGETS
  nn_locator
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
