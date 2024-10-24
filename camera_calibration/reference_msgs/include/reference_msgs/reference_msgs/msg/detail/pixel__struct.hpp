// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/pixel.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__PIXEL__STRUCT_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__PIXEL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__reference_msgs__msg__Pixel __attribute__((deprecated))
#else
# define DEPRECATED__reference_msgs__msg__Pixel __declspec(deprecated)
#endif

namespace reference_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pixel_
{
  using Type = Pixel_<ContainerAllocator>;

  explicit Pixel_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
    }
  }

  explicit Pixel_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->u = 0.0f;
      this->v = 0.0f;
    }
  }

  // field types and members
  using _u_type =
    float;
  _u_type u;
  using _v_type =
    float;
  _v_type v;

  // setters for named parameter idiom
  Type & set__u(
    const float & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const float & _arg)
  {
    this->v = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    reference_msgs::msg::Pixel_<ContainerAllocator> *;
  using ConstRawPtr =
    const reference_msgs::msg::Pixel_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<reference_msgs::msg::Pixel_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<reference_msgs::msg::Pixel_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      reference_msgs::msg::Pixel_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<reference_msgs::msg::Pixel_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      reference_msgs::msg::Pixel_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<reference_msgs::msg::Pixel_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<reference_msgs::msg::Pixel_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<reference_msgs::msg::Pixel_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__reference_msgs__msg__Pixel
    std::shared_ptr<reference_msgs::msg::Pixel_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__reference_msgs__msg__Pixel
    std::shared_ptr<reference_msgs::msg::Pixel_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pixel_ & other) const
  {
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pixel_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pixel_

// alias to use template instance with default allocator
using Pixel =
  reference_msgs::msg::Pixel_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace reference_msgs

#endif  // REFERENCE_MSGS__MSG__DETAIL__PIXEL__STRUCT_HPP_
