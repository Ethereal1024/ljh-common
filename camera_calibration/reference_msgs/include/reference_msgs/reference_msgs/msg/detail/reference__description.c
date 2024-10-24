// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from reference_msgs:msg/Reference.idl
// generated code does not contain a copyright notice

#include "reference_msgs/msg/detail/reference__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_reference_msgs
const rosidl_type_hash_t *
reference_msgs__msg__Reference__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9d, 0x90, 0xc8, 0x5d, 0xef, 0xd4, 0xc3, 0x66,
      0x96, 0x10, 0xa0, 0x23, 0x4c, 0xe6, 0xa9, 0x28,
      0x0c, 0xfe, 0xde, 0xf2, 0x5e, 0xcd, 0x70, 0xaa,
      0xdf, 0x52, 0xc3, 0xc6, 0xab, 0xa6, 0x72, 0x70,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "reference_msgs/msg/detail/pixel__functions.h"
#include "reference_msgs/msg/detail/world_coordinate__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t reference_msgs__msg__Pixel__EXPECTED_HASH = {1, {
    0x9a, 0x21, 0x3a, 0x8a, 0xa3, 0xb2, 0xbc, 0x93,
    0xdd, 0x2c, 0x7d, 0x83, 0x99, 0x64, 0x3f, 0xe6,
    0xcf, 0xf4, 0x2e, 0x72, 0x30, 0x8b, 0xcd, 0x11,
    0x2f, 0x14, 0x7a, 0x6c, 0x3f, 0xd7, 0xd3, 0xee,
  }};
static const rosidl_type_hash_t reference_msgs__msg__WorldCoordinate__EXPECTED_HASH = {1, {
    0x33, 0x8f, 0xb1, 0x40, 0x70, 0xe7, 0x14, 0xa4,
    0x4a, 0x74, 0xb4, 0xc6, 0x53, 0x47, 0xcf, 0x59,
    0x56, 0x3c, 0xe9, 0x8c, 0x32, 0x4a, 0xfc, 0xa0,
    0x3a, 0xb6, 0xa7, 0x22, 0x83, 0x9a, 0x76, 0x32,
  }};
#endif

static char reference_msgs__msg__Reference__TYPE_NAME[] = "reference_msgs/msg/Reference";
static char reference_msgs__msg__Pixel__TYPE_NAME[] = "reference_msgs/msg/Pixel";
static char reference_msgs__msg__WorldCoordinate__TYPE_NAME[] = "reference_msgs/msg/WorldCoordinate";

// Define type names, field names, and default values
static char reference_msgs__msg__Reference__FIELD_NAME__vec_u[] = "vec_u";
static char reference_msgs__msg__Reference__FIELD_NAME__vec_x[] = "vec_x";
static char reference_msgs__msg__Reference__FIELD_NAME__delivering[] = "delivering";

static rosidl_runtime_c__type_description__Field reference_msgs__msg__Reference__FIELDS[] = {
  {
    {reference_msgs__msg__Reference__FIELD_NAME__vec_u, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {reference_msgs__msg__Pixel__TYPE_NAME, 24, 24},
    },
    {NULL, 0, 0},
  },
  {
    {reference_msgs__msg__Reference__FIELD_NAME__vec_x, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {reference_msgs__msg__WorldCoordinate__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {reference_msgs__msg__Reference__FIELD_NAME__delivering, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription reference_msgs__msg__Reference__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {reference_msgs__msg__Pixel__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
  {
    {reference_msgs__msg__WorldCoordinate__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
reference_msgs__msg__Reference__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {reference_msgs__msg__Reference__TYPE_NAME, 28, 28},
      {reference_msgs__msg__Reference__FIELDS, 3, 3},
    },
    {reference_msgs__msg__Reference__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&reference_msgs__msg__Pixel__EXPECTED_HASH, reference_msgs__msg__Pixel__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = reference_msgs__msg__Pixel__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&reference_msgs__msg__WorldCoordinate__EXPECTED_HASH, reference_msgs__msg__WorldCoordinate__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = reference_msgs__msg__WorldCoordinate__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# msg/Reference.msg\n"
  "Pixel vec_u\n"
  "WorldCoordinate vec_x\n"
  "bool delivering";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
reference_msgs__msg__Reference__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {reference_msgs__msg__Reference__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 69, 69},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
reference_msgs__msg__Reference__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *reference_msgs__msg__Reference__get_individual_type_description_source(NULL),
    sources[1] = *reference_msgs__msg__Pixel__get_individual_type_description_source(NULL);
    sources[2] = *reference_msgs__msg__WorldCoordinate__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
