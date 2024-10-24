// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "reference_msgs/msg/detail/pixel__functions.h"
#include "reference_msgs/msg/detail/pixel__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace reference_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Pixel_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) reference_msgs::msg::Pixel(_init);
}

void Pixel_fini_function(void * message_memory)
{
  auto typed_message = static_cast<reference_msgs::msg::Pixel *>(message_memory);
  typed_message->~Pixel();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Pixel_message_member_array[2] = {
  {
    "u",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(reference_msgs::msg::Pixel, u),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "v",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(reference_msgs::msg::Pixel, v),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Pixel_message_members = {
  "reference_msgs::msg",  // message namespace
  "Pixel",  // message name
  2,  // number of fields
  sizeof(reference_msgs::msg::Pixel),
  false,  // has_any_key_member_
  Pixel_message_member_array,  // message members
  Pixel_init_function,  // function to initialize message memory (memory has to be allocated)
  Pixel_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Pixel_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Pixel_message_members,
  get_message_typesupport_handle_function,
  &reference_msgs__msg__Pixel__get_type_hash,
  &reference_msgs__msg__Pixel__get_type_description,
  &reference_msgs__msg__Pixel__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace reference_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<reference_msgs::msg::Pixel>()
{
  return &::reference_msgs::msg::rosidl_typesupport_introspection_cpp::Pixel_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, reference_msgs, msg, Pixel)() {
  return &::reference_msgs::msg::rosidl_typesupport_introspection_cpp::Pixel_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
