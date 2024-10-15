cmake_minimum_required(VERSION 3.8)
project(tracker)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(founder_msgs REQUIRED)

add_executable(tracker src/Tracker.cpp)
add_executable(founder src/Founder.cpp)

ament_target_dependencies(tracker rclcpp founder_msgs)
ament_target_dependencies(founder rclcpp founder_msgs)

install(TARGETS
  tracker
  founder
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
