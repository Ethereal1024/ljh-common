// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/pixel.h"


#ifndef REFERENCE_MSGS__MSG__DETAIL__PIXEL__STRUCT_H_
#define REFERENCE_MSGS__MSG__DETAIL__PIXEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Pixel in the package reference_msgs.
/**
  * msg/Pixel.msg
 */
typedef struct reference_msgs__msg__Pixel
{
  float u;
  float v;
} reference_msgs__msg__Pixel;

// Struct for a sequence of reference_msgs__msg__Pixel.
typedef struct reference_msgs__msg__Pixel__Sequence
{
  reference_msgs__msg__Pixel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} reference_msgs__msg__Pixel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // REFERENCE_MSGS__MSG__DETAIL__PIXEL__STRUCT_H_
