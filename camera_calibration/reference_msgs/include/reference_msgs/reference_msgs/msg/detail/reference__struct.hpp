// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from reference_msgs:msg/Reference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/reference.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__REFERENCE__STRUCT_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__REFERENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'vec_u'
#include "reference_msgs/msg/detail/pixel__struct.hpp"
// Member 'vec_x'
#include "reference_msgs/msg/detail/world_coordinate__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__reference_msgs__msg__Reference __attribute__((deprecated))
#else
# define DEPRECATED__reference_msgs__msg__Reference __declspec(deprecated)
#endif

namespace reference_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Reference_
{
  using Type = Reference_<ContainerAllocator>;

  explicit Reference_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vec_u(_init),
    vec_x(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->delivering = false;
    }
  }

  explicit Reference_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vec_u(_alloc, _init),
    vec_x(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->delivering = false;
    }
  }

  // field types and members
  using _vec_u_type =
    reference_msgs::msg::Pixel_<ContainerAllocator>;
  _vec_u_type vec_u;
  using _vec_x_type =
    reference_msgs::msg::WorldCoordinate_<ContainerAllocator>;
  _vec_x_type vec_x;
  using _delivering_type =
    bool;
  _delivering_type delivering;

  // setters for named parameter idiom
  Type & set__vec_u(
    const reference_msgs::msg::Pixel_<ContainerAllocator> & _arg)
  {
    this->vec_u = _arg;
    return *this;
  }
  Type & set__vec_x(
    const reference_msgs::msg::WorldCoordinate_<ContainerAllocator> & _arg)
  {
    this->vec_x = _arg;
    return *this;
  }
  Type & set__delivering(
    const bool & _arg)
  {
    this->delivering = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    reference_msgs::msg::Reference_<ContainerAllocator> *;
  using ConstRawPtr =
    const reference_msgs::msg::Reference_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<reference_msgs::msg::Reference_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<reference_msgs::msg::Reference_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      reference_msgs::msg::Reference_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<reference_msgs::msg::Reference_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      reference_msgs::msg::Reference_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<reference_msgs::msg::Reference_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<reference_msgs::msg::Reference_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<reference_msgs::msg::Reference_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__reference_msgs__msg__Reference
    std::shared_ptr<reference_msgs::msg::Reference_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__reference_msgs__msg__Reference
    std::shared_ptr<reference_msgs::msg::Reference_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Reference_ & other) const
  {
    if (this->vec_u != other.vec_u) {
      return false;
    }
    if (this->vec_x != other.vec_x) {
      return false;
    }
    if (this->delivering != other.delivering) {
      return false;
    }
    return true;
  }
  bool operator!=(const Reference_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Reference_

// alias to use template instance with default allocator
using Reference =
  reference_msgs::msg::Reference_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace reference_msgs

#endif  // REFERENCE_MSGS__MSG__DETAIL__REFERENCE__STRUCT_HPP_
