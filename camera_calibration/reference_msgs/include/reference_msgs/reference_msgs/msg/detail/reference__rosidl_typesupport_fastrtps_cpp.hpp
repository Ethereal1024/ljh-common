// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from reference_msgs:msg/Reference.idl
// generated code does not contain a copyright notice

#ifndef REFERENCE_MSGS__MSG__DETAIL__REFERENCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__REFERENCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "reference_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "reference_msgs/msg/detail/reference__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace reference_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
cdr_serialize(
  const reference_msgs::msg::Reference & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  reference_msgs::msg::Reference & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
get_serialized_size(
  const reference_msgs::msg::Reference & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
max_serialized_size_Reference(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
cdr_serialize_key(
  const reference_msgs::msg::Reference & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
get_serialized_size_key(
  const reference_msgs::msg::Reference & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
max_serialized_size_key_Reference(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace reference_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_reference_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, reference_msgs, msg, Reference)();

#ifdef __cplusplus
}
#endif

#endif  // REFERENCE_MSGS__MSG__DETAIL__REFERENCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
