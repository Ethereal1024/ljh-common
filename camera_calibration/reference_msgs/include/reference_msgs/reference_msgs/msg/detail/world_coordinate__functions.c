// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from reference_msgs:msg/WorldCoordinate.idl
// generated code does not contain a copyright notice
#include "reference_msgs/msg/detail/world_coordinate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
reference_msgs__msg__WorldCoordinate__init(reference_msgs__msg__WorldCoordinate * msg)
{
  if (!msg) {
    return false;
  }
  // x_w
  // y_w
  // z_w
  return true;
}

void
reference_msgs__msg__WorldCoordinate__fini(reference_msgs__msg__WorldCoordinate * msg)
{
  if (!msg) {
    return;
  }
  // x_w
  // y_w
  // z_w
}

bool
reference_msgs__msg__WorldCoordinate__are_equal(const reference_msgs__msg__WorldCoordinate * lhs, const reference_msgs__msg__WorldCoordinate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_w
  if (lhs->x_w != rhs->x_w) {
    return false;
  }
  // y_w
  if (lhs->y_w != rhs->y_w) {
    return false;
  }
  // z_w
  if (lhs->z_w != rhs->z_w) {
    return false;
  }
  return true;
}

bool
reference_msgs__msg__WorldCoordinate__copy(
  const reference_msgs__msg__WorldCoordinate * input,
  reference_msgs__msg__WorldCoordinate * output)
{
  if (!input || !output) {
    return false;
  }
  // x_w
  output->x_w = input->x_w;
  // y_w
  output->y_w = input->y_w;
  // z_w
  output->z_w = input->z_w;
  return true;
}

reference_msgs__msg__WorldCoordinate *
reference_msgs__msg__WorldCoordinate__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  reference_msgs__msg__WorldCoordinate * msg = (reference_msgs__msg__WorldCoordinate *)allocator.allocate(sizeof(reference_msgs__msg__WorldCoordinate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(reference_msgs__msg__WorldCoordinate));
  bool success = reference_msgs__msg__WorldCoordinate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
reference_msgs__msg__WorldCoordinate__destroy(reference_msgs__msg__WorldCoordinate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    reference_msgs__msg__WorldCoordinate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
reference_msgs__msg__WorldCoordinate__Sequence__init(reference_msgs__msg__WorldCoordinate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  reference_msgs__msg__WorldCoordinate * data = NULL;

  if (size) {
    data = (reference_msgs__msg__WorldCoordinate *)allocator.zero_allocate(size, sizeof(reference_msgs__msg__WorldCoordinate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = reference_msgs__msg__WorldCoordinate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        reference_msgs__msg__WorldCoordinate__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
reference_msgs__msg__WorldCoordinate__Sequence__fini(reference_msgs__msg__WorldCoordinate__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      reference_msgs__msg__WorldCoordinate__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

reference_msgs__msg__WorldCoordinate__Sequence *
reference_msgs__msg__WorldCoordinate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  reference_msgs__msg__WorldCoordinate__Sequence * array = (reference_msgs__msg__WorldCoordinate__Sequence *)allocator.allocate(sizeof(reference_msgs__msg__WorldCoordinate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = reference_msgs__msg__WorldCoordinate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
reference_msgs__msg__WorldCoordinate__Sequence__destroy(reference_msgs__msg__WorldCoordinate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    reference_msgs__msg__WorldCoordinate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
reference_msgs__msg__WorldCoordinate__Sequence__are_equal(const reference_msgs__msg__WorldCoordinate__Sequence * lhs, const reference_msgs__msg__WorldCoordinate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!reference_msgs__msg__WorldCoordinate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
reference_msgs__msg__WorldCoordinate__Sequence__copy(
  const reference_msgs__msg__WorldCoordinate__Sequence * input,
  reference_msgs__msg__WorldCoordinate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(reference_msgs__msg__WorldCoordinate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    reference_msgs__msg__WorldCoordinate * data =
      (reference_msgs__msg__WorldCoordinate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!reference_msgs__msg__WorldCoordinate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          reference_msgs__msg__WorldCoordinate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!reference_msgs__msg__WorldCoordinate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
