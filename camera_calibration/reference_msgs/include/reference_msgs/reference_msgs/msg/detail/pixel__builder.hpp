// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/pixel.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__PIXEL__BUILDER_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__PIXEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "reference_msgs/msg/detail/pixel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace reference_msgs
{

namespace msg
{

namespace builder
{

class Init_Pixel_v
{
public:
  explicit Init_Pixel_v(::reference_msgs::msg::Pixel & msg)
  : msg_(msg)
  {}
  ::reference_msgs::msg::Pixel v(::reference_msgs::msg::Pixel::_v_type arg)
  {
    msg_.v = std::move(arg);
    return std::move(msg_);
  }

private:
  ::reference_msgs::msg::Pixel msg_;
};

class Init_Pixel_u
{
public:
  Init_Pixel_u()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pixel_v u(::reference_msgs::msg::Pixel::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_Pixel_v(msg_);
  }

private:
  ::reference_msgs::msg::Pixel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::reference_msgs::msg::Pixel>()
{
  return reference_msgs::msg::builder::Init_Pixel_u();
}

}  // namespace reference_msgs

#endif  // REFERENCE_MSGS__MSG__DETAIL__PIXEL__BUILDER_HPP_
