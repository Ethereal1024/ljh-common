// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from reference_msgs:msg/WorldCoordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/world_coordinate.h"


#ifndef REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__STRUCT_H_
#define REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/WorldCoordinate in the package reference_msgs.
/**
  * msg/WorldCoordinate.msg
 */
typedef struct reference_msgs__msg__WorldCoordinate
{
  float x_w;
  float y_w;
  float z_w;
} reference_msgs__msg__WorldCoordinate;

// Struct for a sequence of reference_msgs__msg__WorldCoordinate.
typedef struct reference_msgs__msg__WorldCoordinate__Sequence
{
  reference_msgs__msg__WorldCoordinate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} reference_msgs__msg__WorldCoordinate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__STRUCT_H_
