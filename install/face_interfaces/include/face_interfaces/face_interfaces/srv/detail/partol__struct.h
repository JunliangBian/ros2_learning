// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from face_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice

#ifndef FACE_INTERFACES__SRV__DETAIL__PARTOL__STRUCT_H_
#define FACE_INTERFACES__SRV__DETAIL__PARTOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Partol in the package face_interfaces.
typedef struct face_interfaces__srv__Partol_Request
{
  float target_x;
  float target_y;
} face_interfaces__srv__Partol_Request;

// Struct for a sequence of face_interfaces__srv__Partol_Request.
typedef struct face_interfaces__srv__Partol_Request__Sequence
{
  face_interfaces__srv__Partol_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} face_interfaces__srv__Partol_Request__Sequence;


// Constants defined in the message

/// Constant 'SUCESS'.
enum
{
  face_interfaces__srv__Partol_Response__SUCESS = 1
};

/// Constant 'FAIL'.
enum
{
  face_interfaces__srv__Partol_Response__FAIL = 0
};

/// Struct defined in srv/Partol in the package face_interfaces.
typedef struct face_interfaces__srv__Partol_Response
{
  /// 结果，SUCESS
  int8_t result;
} face_interfaces__srv__Partol_Response;

// Struct for a sequence of face_interfaces__srv__Partol_Response.
typedef struct face_interfaces__srv__Partol_Response__Sequence
{
  face_interfaces__srv__Partol_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} face_interfaces__srv__Partol_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FACE_INTERFACES__SRV__DETAIL__PARTOL__STRUCT_H_
