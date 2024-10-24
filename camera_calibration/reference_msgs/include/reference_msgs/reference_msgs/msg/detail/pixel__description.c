// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from reference_msgs:msg/Pixel.idl
// generated code does not contain a copyright notice

#include "reference_msgs/msg/detail/pixel__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_type_hash_t *
reference_msgs__msg__Pixel__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0x21, 0x3a, 0x8a, 0xa3, 0xb2, 0xbc, 0x93,
      0xdd, 0x2c, 0x7d, 0x83, 0x99, 0x64, 0x3f, 0xe6,
      0xcf, 0xf4, 0x2e, 0x72, 0x30, 0x8b, 0xcd, 0x11,
      0x2f, 0x14, 0x7a, 0x6c, 0x3f, 0xd7, 0xd3, 0xee,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char reference_msgs__msg__Pixel__TYPE_NAME[] = "reference_msgs/msg/Pixel";

// Define type names, field names, and default values
static char reference_msgs__msg__Pixel__FIELD_NAME__u[] = "u";
static char reference_msgs__msg__Pixel__FIELD_NAME__v[] = "v";

static rosidl_runtime_c__type_description__Field reference_msgs__msg__Pixel__FIELDS[] = {
  {
    {reference_msgs__msg__Pixel__FIELD_NAME__u, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {reference_msgs__msg__Pixel__FIELD_NAME__v, 1, 1},
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
reference_msgs__msg__Pixel__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {reference_msgs__msg__Pixel__TYPE_NAME, 24, 24},
      {reference_msgs__msg__Pixel__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# msg/Pixel.msg\n"
  "float32 u\n"
  "float32 v";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
reference_msgs__msg__Pixel__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {reference_msgs__msg__Pixel__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 35, 35},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
reference_msgs__msg__Pixel__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *reference_msgs__msg__Pixel__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
