// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice
#include "reference_msgs/msg/detail/pixel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
reference_msgs__msg__Pixel__init(reference_msgs__msg__Pixel * msg)
{
  if (!msg) {
    return false;
  }
  // u
  // v
  return true;
}

void
reference_msgs__msg__Pixel__fini(reference_msgs__msg__Pixel * msg)
{
  if (!msg) {
    return;
  }
  // u
  // v
}

bool
reference_msgs__msg__Pixel__are_equal(const reference_msgs__msg__Pixel * lhs, const reference_msgs__msg__Pixel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // u
  if (lhs->u != rhs->u) {
    return false;
  }
  // v
  if (lhs->v != rhs->v) {
    return false;
  }
  return true;
}

bool
reference_msgs__msg__Pixel__copy(
  const reference_msgs__msg__Pixel * input,
  reference_msgs__msg__Pixel * output)
{
  if (!input || !output) {
    return false;
  }
  // u
  output->u = input->u;
  // v
  output->v = input->v;
  return true;
}

reference_msgs__msg__Pixel *
reference_msgs__msg__Pixel__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  reference_msgs__msg__Pixel * msg = (reference_msgs__msg__Pixel *)allocator.allocate(sizeof(reference_msgs__msg__Pixel), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(reference_msgs__msg__Pixel));
  bool success = reference_msgs__msg__Pixel__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
reference_msgs__msg__Pixel__destroy(reference_msgs__msg__Pixel * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    reference_msgs__msg__Pixel__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
reference_msgs__msg__Pixel__Sequence__init(reference_msgs__msg__Pixel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  reference_msgs__msg__Pixel * data = NULL;

  if (size) {
    data = (reference_msgs__msg__Pixel *)allocator.zero_allocate(size, sizeof(reference_msgs__msg__Pixel), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = reference_msgs__msg__Pixel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        reference_msgs__msg__Pixel__fini(&data[i - 1]);
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
reference_msgs__msg__Pixel__Sequence__fini(reference_msgs__msg__Pixel__Sequence * array)
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
      reference_msgs__msg__Pixel__fini(&array->data[i]);
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

reference_msgs__msg__Pixel__Sequence *
reference_msgs__msg__Pixel__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  reference_msgs__msg__Pixel__Sequence * array = (reference_msgs__msg__Pixel__Sequence *)allocator.allocate(sizeof(reference_msgs__msg__Pixel__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = reference_msgs__msg__Pixel__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
reference_msgs__msg__Pixel__Sequence__destroy(reference_msgs__msg__Pixel__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    reference_msgs__msg__Pixel__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
reference_msgs__msg__Pixel__Sequence__are_equal(const reference_msgs__msg__Pixel__Sequence * lhs, const reference_msgs__msg__Pixel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!reference_msgs__msg__Pixel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
reference_msgs__msg__Pixel__Sequence__copy(
  const reference_msgs__msg__Pixel__Sequence * input,
  reference_msgs__msg__Pixel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(reference_msgs__msg__Pixel);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    reference_msgs__msg__Pixel * data =
      (reference_msgs__msg__Pixel *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!reference_msgs__msg__Pixel__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          reference_msgs__msg__Pixel__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!reference_msgs__msg__Pixel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
