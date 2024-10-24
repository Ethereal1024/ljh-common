// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from reference_msgs:msg/Reference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/reference.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__REFERENCE__BUILDER_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__REFERENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "reference_msgs/msg/detail/reference__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace reference_msgs
{

namespace msg
{

namespace builder
{

class Init_Reference_delivering
{
public:
  explicit Init_Reference_delivering(::reference_msgs::msg::Reference & msg)
  : msg_(msg)
  {}
  ::reference_msgs::msg::Reference delivering(::reference_msgs::msg::Reference::_delivering_type arg)
  {
    msg_.delivering = std::move(arg);
    return std::move(msg_);
  }

private:
  ::reference_msgs::msg::Reference msg_;
};

class Init_Reference_vec_x
{
public:
  explicit Init_Reference_vec_x(::reference_msgs::msg::Reference & msg)
  : msg_(msg)
  {}
  Init_Reference_delivering vec_x(::reference_msgs::msg::Reference::_vec_x_type arg)
  {
    msg_.vec_x = std::move(arg);
    return Init_Reference_delivering(msg_);
  }

private:
  ::reference_msgs::msg::Reference msg_;
};

class Init_Reference_vec_u
{
public:
  Init_Reference_vec_u()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Reference_vec_x vec_u(::reference_msgs::msg::Reference::_vec_u_type arg)
  {
    msg_.vec_u = std::move(arg);
    return Init_Reference_vec_x(msg_);
  }

private:
  ::reference_msgs::msg::Reference msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::reference_msgs::msg::Reference>()
{
  return reference_msgs::msg::builder::Init_Reference_vec_u();
}

}  // namespace reference_msgs

#endif  // REFERENCE_MSGS__MSG__DETAIL__REFERENCE__BUILDER_HPP_
