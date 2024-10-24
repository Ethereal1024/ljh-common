// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from reference_msgs:msg/WorldCoordinate.idl
// generated code does not contain a copyright notice

#include "reference_msgs/msg/detail/world_coordinate__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_type_hash_t *
reference_msgs__msg__WorldCoordinate__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x33, 0x8f, 0xb1, 0x40, 0x70, 0xe7, 0x14, 0xa4,
      0x4a, 0x74, 0xb4, 0xc6, 0x53, 0x47, 0xcf, 0x59,
      0x56, 0x3c, 0xe9, 0x8c, 0x32, 0x4a, 0xfc, 0xa0,
      0x3a, 0xb6, 0xa7, 0x22, 0x83, 0x9a, 0x76, 0x32,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char reference_msgs__msg__WorldCoordinate__TYPE_NAME[] = "reference_msgs/msg/WorldCoordinate";

// Define type names, field names, and default values
static char reference_msgs__msg__WorldCoordinate__FIELD_NAME__x_w[] = "x_w";
static char reference_msgs__msg__WorldCoordinate__FIELD_NAME__y_w[] = "y_w";
static char reference_msgs__msg__WorldCoordinate__FIELD_NAME__z_w[] = "z_w";

static rosidl_runtime_c__type_description__Field reference_msgs__msg__WorldCoordinate__FIELDS[] = {
  {
    {reference_msgs__msg__WorldCoordinate__FIELD_NAME__x_w, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {reference_msgs__msg__WorldCoordinate__FIELD_NAME__y_w, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {reference_msgs__msg__WorldCoordinate__FIELD_NAME__z_w, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
reference_msgs__msg__WorldCoordinate__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {reference_msgs__msg__WorldCoordinate__TYPE_NAME, 34, 34},
      {reference_msgs__msg__WorldCoordinate__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# msg/WorldCoordinate.msg\n"
  "float32 x_w\n"
  "float32 y_w\n"
  "float32 z_w";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
reference_msgs__msg__WorldCoordinate__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {reference_msgs__msg__WorldCoordinate__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 61, 61},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
reference_msgs__msg__WorldCoordinate__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *reference_msgs__msg__WorldCoordinate__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
