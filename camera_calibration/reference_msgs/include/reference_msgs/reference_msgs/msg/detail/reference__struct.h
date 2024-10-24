// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from reference_msgs:msg/Reference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/reference.h"


#ifndef REFERENCE_MSGS__MSG__DETAIL__REFERENCE__STRUCT_H_
#define REFERENCE_MSGS__MSG__DETAIL__REFERENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'vec_u'
#include "reference_msgs/msg/detail/pixel__struct.h"
// Member 'vec_x'
#include "reference_msgs/msg/detail/world_coordinate__struct.h"

/// Struct defined in msg/Reference in the package reference_msgs.
/**
  * msg/Reference.msg
 */
typedef struct reference_msgs__msg__Reference
{
  reference_msgs__msg__Pixel vec_u;
  reference_msgs__msg__WorldCoordinate vec_x;
  bool delivering;
} reference_msgs__msg__Reference;

// Struct for a sequence of reference_msgs__msg__Reference.
typedef struct reference_msgs__msg__Reference__Sequence
{
  reference_msgs__msg__Reference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} reference_msgs__msg__Reference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFERENCE_MSGS__MSG__DETAIL__REFERENCE__STRUCT_H_
