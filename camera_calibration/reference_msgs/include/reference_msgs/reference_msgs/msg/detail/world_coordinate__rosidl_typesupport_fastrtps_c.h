// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from reference_msgs:msg/WorldCoordinate.idl
// generated code does not contain a copyright notice
#ifndef REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "reference_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "reference_msgs/msg/detail/world_coordinate__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
bool cdr_serialize_reference_msgs__msg__WorldCoordinate(
  const reference_msgs__msg__WorldCoordinate * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
bool cdr_deserialize_reference_msgs__msg__WorldCoordinate(
  eprosima::fastcdr::Cdr &,
  reference_msgs__msg__WorldCoordinate * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
size_t get_serialized_size_reference_msgs__msg__WorldCoordinate(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
size_t max_serialized_size_reference_msgs__msg__WorldCoordinate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
bool cdr_serialize_key_reference_msgs__msg__WorldCoordinate(
  const reference_msgs__msg__WorldCoordinate * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
size_t get_serialized_size_key_reference_msgs__msg__WorldCoordinate(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
size_t max_serialized_size_key_reference_msgs__msg__WorldCoordinate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_reference_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, reference_msgs, msg, WorldCoordinate)();

#ifdef __cplusplus
}
#endif

#endif  // REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
