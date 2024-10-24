// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from reference_msgs:msg/WorldCoordinate.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "reference_msgs/msg/world_coordinate.hpp"


#ifndef REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__STRUCT_HPP_
#define REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__reference_msgs__msg__WorldCoordinate __attribute__((deprecated))
#else
# define DEPRECATED__reference_msgs__msg__WorldCoordinate __declspec(deprecated)
#endif

namespace reference_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WorldCoordinate_
{
  using Type = WorldCoordinate_<ContainerAllocator>;

  explicit WorldCoordinate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_w = 0.0f;
      this->y_w = 0.0f;
      this->z_w = 0.0f;
    }
  }

  explicit WorldCoordinate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_w = 0.0f;
      this->y_w = 0.0f;
      this->z_w = 0.0f;
    }
  }

  // field types and members
  using _x_w_type =
    float;
  _x_w_type x_w;
  using _y_w_type =
    float;
  _y_w_type y_w;
  using _z_w_type =
    float;
  _z_w_type z_w;

  // setters for named parameter idiom
  Type & set__x_w(
    const float & _arg)
  {
    this->x_w = _arg;
    return *this;
  }
  Type & set__y_w(
    const float & _arg)
  {
    this->y_w = _arg;
    return *this;
  }
  Type & set__z_w(
    const float & _arg)
  {
    this->z_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    reference_msgs::msg::WorldCoordinate_<ContainerAllocator> *;
  using ConstRawPtr =
    const reference_msgs::msg::WorldCoordinate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      reference_msgs::msg::WorldCoordinate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      reference_msgs::msg::WorldCoordinate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__reference_msgs__msg__WorldCoordinate
    std::shared_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__reference_msgs__msg__WorldCoordinate
    std::shared_ptr<reference_msgs::msg::WorldCoordinate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WorldCoordinate_ & other) const
  {
    if (this->x_w != other.x_w) {
      return false;
    }
    if (this->y_w != other.y_w) {
      return false;
    }
    if (this->z_w != other.z_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const WorldCoordinate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WorldCoordinate_

// alias to use template instance with default allocator
using WorldCoordinate =
  reference_msgs::msg::WorldCoordinate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace reference_msgs

#endif  // REFERENCE_MSGS__MSG__DETAIL__WORLD_COORDINATE__STRUCT_HPP_
