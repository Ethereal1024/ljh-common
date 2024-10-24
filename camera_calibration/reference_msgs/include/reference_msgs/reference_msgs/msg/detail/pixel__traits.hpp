// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/pixel.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__PIXEL__TRAITS_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__PIXEL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "reference_msgs/msg/detail/pixel__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace reference_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Pixel & msg,
  std::ostream & out)
{
  out << "{";
  // member: u
  {
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << ", ";
  }

  // member: v
  {
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pixel & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "u: ";
    rosidl_generator_traits::value_to_yaml(msg.u, out);
    out << "\n";
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pixel & msg, bool use_flow_style = false)
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
  const reference_msgs::msg::Pixel & msg,
  std::ostream & out, size_t indentation = 0)
{
  reference_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use reference_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const reference_msgs::msg::Pixel & msg)
{
  return reference_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<reference_msgs::msg::Pixel>()
{
  return "reference_msgs::msg::Pixel";
}

template<>
inline const char * name<reference_msgs::msg::Pixel>()
{
  return "reference_msgs/msg/Pixel";
}

template<>
struct has_fixed_size<reference_msgs::msg::Pixel>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<reference_msgs::msg::Pixel>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<reference_msgs::msg::Pixel>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // REFERENCE_MSGS__MSG__DETAIL__PIXEL__TRAITS_HPP_
