// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from reference_msgs:msg/WorldCoordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/world_coordinate.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__BUILDER_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "reference_msgs/msg/detail/world_coordinate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace reference_msgs
{

namespace msg
{

namespace builder
{

class Init_WorldCoordinate_z_w
{
public:
  explicit Init_WorldCoordinate_z_w(::reference_msgs::msg::WorldCoordinate & msg)
  : msg_(msg)
  {}
  ::reference_msgs::msg::WorldCoordinate z_w(::reference_msgs::msg::WorldCoordinate::_z_w_type arg)
  {
    msg_.z_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::reference_msgs::msg::WorldCoordinate msg_;
};

class Init_WorldCoordinate_y_w
{
public:
  explicit Init_WorldCoordinate_y_w(::reference_msgs::msg::WorldCoordinate & msg)
  : msg_(msg)
  {}
  Init_WorldCoordinate_z_w y_w(::reference_msgs::msg::WorldCoordinate::_y_w_type arg)
  {
    msg_.y_w = std::move(arg);
    return Init_WorldCoordinate_z_w(msg_);
  }

private:
  ::reference_msgs::msg::WorldCoordinate msg_;
};

class Init_WorldCoordinate_x_w
{
public:
  Init_WorldCoordinate_x_w()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorldCoordinate_y_w x_w(::reference_msgs::msg::WorldCoordinate::_x_w_type arg)
  {
    msg_.x_w = std::move(arg);
    return Init_WorldCoordinate_y_w(msg_);
  }

private:
  ::reference_msgs::msg::WorldCoordinate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::reference_msgs::msg::WorldCoordinate>()
{
  return reference_msgs::msg::builder::Init_WorldCoordinate_x_w();
}

}  // namespace reference_msgs

#endif  // REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__BUILDER_HPP_
