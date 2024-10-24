// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/pixel.h"


#ifndef REFERENCE_MSGS__MSG__DETAIL__PIXEL__FUNCTIONS_H_
#define REFERENCE_MSGS__MSG__DETAIL__PIXEL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "reference_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "reference_msgs/msg/detail/pixel__struct.h"

/// Initialize msg/Pixel message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * reference_msgs__msg__Pixel
 * )) before or use
 * reference_msgs__msg__Pixel__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
bool
reference_msgs__msg__Pixel__init(reference_msgs__msg__Pixel * msg);

/// Finalize msg/Pixel message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
void
reference_msgs__msg__Pixel__fini(reference_msgs__msg__Pixel * msg);

/// Create msg/Pixel message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * reference_msgs__msg__Pixel__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
reference_msgs__msg__Pixel *
reference_msgs__msg__Pixel__create(void);

/// Destroy msg/Pixel message.
/**
 * It calls
 * reference_msgs__msg__Pixel__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
void
reference_msgs__msg__Pixel__destroy(reference_msgs__msg__Pixel * msg);

/// Check for msg/Pixel message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
bool
reference_msgs__msg__Pixel__are_equal(const reference_msgs__msg__Pixel * lhs, const reference_msgs__msg__Pixel * rhs);

/// Copy a msg/Pixel message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
bool
reference_msgs__msg__Pixel__copy(
  const reference_msgs__msg__Pixel * input,
  reference_msgs__msg__Pixel * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_type_hash_t *
reference_msgs__msg__Pixel__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_runtime_c__type_description__TypeDescription *
reference_msgs__msg__Pixel__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_runtime_c__type_description__TypeSource *
reference_msgs__msg__Pixel__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
reference_msgs__msg__Pixel__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/Pixel messages.
/**
 * It allocates the memory for the number of elements and calls
 * reference_msgs__msg__Pixel__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
bool
reference_msgs__msg__Pixel__Sequence__init(reference_msgs__msg__Pixel__Sequence * array, size_t size);

/// Finalize array of msg/Pixel messages.
/**
 * It calls
 * reference_msgs__msg__Pixel__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
void
reference_msgs__msg__Pixel__Sequence__fini(reference_msgs__msg__Pixel__Sequence * array);

/// Create array of msg/Pixel messages.
/**
 * It allocates the memory for the array and calls
 * reference_msgs__msg__Pixel__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
reference_msgs__msg__Pixel__Sequence *
reference_msgs__msg__Pixel__Sequence__create(size_t size);

/// Destroy array of msg/Pixel messages.
/**
 * It calls
 * reference_msgs__msg__Pixel__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
void
reference_msgs__msg__Pixel__Sequence__destroy(reference_msgs__msg__Pixel__Sequence * array);

/// Check for msg/Pixel message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
bool
reference_msgs__msg__Pixel__Sequence__are_equal(const reference_msgs__msg__Pixel__Sequence * lhs, const reference_msgs__msg__Pixel__Sequence * rhs);

/// Copy an array of msg/Pixel messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
bool
reference_msgs__msg__Pixel__Sequence__copy(
  const reference_msgs__msg__Pixel__Sequence * input,
  reference_msgs__msg__Pixel__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // REFERENCE_MSGS__MSG__DETAIL__PIXEL__FUNCTIONS_H_
