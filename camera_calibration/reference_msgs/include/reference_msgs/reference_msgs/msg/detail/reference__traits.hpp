// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from reference_msgs:msg/Reference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/reference.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__REFERENCE__TRAITS_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__REFERENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "reference_msgs/msg/detail/reference__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'vec_u'
#include "reference_msgs/msg/detail/pixel__traits.hpp"
// Member 'vec_x'
#include "reference_msgs/msg/detail/world_coordinate__traits.hpp"

namespace reference_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Reference & msg,
  std::ostream & out)
{
  out << "{";
  // member: vec_u
  {
    out << "vec_u: ";
    to_flow_style_yaml(msg.vec_u, out);
    out << ", ";
  }

  // member: vec_x
  {
    out << "vec_x: ";
    to_flow_style_yaml(msg.vec_x, out);
    out << ", ";
  }

  // member: delivering
  {
    out << "delivering: ";
    rosidl_generator_traits::value_to_yaml(msg.delivering, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Reference & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vec_u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vec_u:\n";
    to_block_style_yaml(msg.vec_u, out, indentation + 2);
  }

  // member: vec_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vec_x:\n";
    to_block_style_yaml(msg.vec_x, out, indentation + 2);
  }

  // member: delivering
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "delivering: ";
    rosidl_generator_traits::value_to_yaml(msg.delivering, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Reference & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace reference_msgs

namespace rosidl_generator_traits
{

[[deprecated("use reference_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const reference_msgs::msg::Reference & msg,
  std::ostream & out, size_t indentation = 0)
{
  reference_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use reference_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const reference_msgs::msg::Reference & msg)
{
  return reference_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<reference_msgs::msg::Reference>()
{
  return "reference_msgs::msg::Reference";
}

template<>
inline const char * name<reference_msgs::msg::Reference>()
{
  return "reference_msgs/msg/Reference";
}

template<>
struct has_fixed_size<reference_msgs::msg::Reference>
  : std::integral_constant<bool, has_fixed_size<reference_msgs::msg::Pixel>::value && has_fixed_size<reference_msgs::msg::WorldCoordinate>::value> {};

template<>
struct has_bounded_size<reference_msgs::msg::Reference>
  : std::integral_constant<bool, has_bounded_size<reference_msgs::msg::Pixel>::value && has_bounded_size<reference_msgs::msg::WorldCoordinate>::value> {};

template<>
struct is_message<reference_msgs::msg::Reference>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REFERENCE_MSGS__MSG__DETAIL__REFERENCE__TRAITS_HPP_
