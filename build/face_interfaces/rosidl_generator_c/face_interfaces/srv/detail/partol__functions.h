// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from face_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice

#ifndef FACE_INTERFACES__SRV__DETAIL__PARTOL__FUNCTIONS_H_
#define FACE_INTERFACES__SRV__DETAIL__PARTOL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "face_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "face_interfaces/srv/detail/partol__struct.h"

/// Initialize srv/Partol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * face_interfaces__srv__Partol_Request
 * )) before or use
 * face_interfaces__srv__Partol_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Request__init(face_interfaces__srv__Partol_Request * msg);

/// Finalize srv/Partol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Request__fini(face_interfaces__srv__Partol_Request * msg);

/// Create srv/Partol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * face_interfaces__srv__Partol_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
face_interfaces__srv__Partol_Request *
face_interfaces__srv__Partol_Request__create();

/// Destroy srv/Partol message.
/**
 * It calls
 * face_interfaces__srv__Partol_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Request__destroy(face_interfaces__srv__Partol_Request * msg);

/// Check for srv/Partol message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Request__are_equal(const face_interfaces__srv__Partol_Request * lhs, const face_interfaces__srv__Partol_Request * rhs);

/// Copy a srv/Partol message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Request__copy(
  const face_interfaces__srv__Partol_Request * input,
  face_interfaces__srv__Partol_Request * output);

/// Initialize array of srv/Partol messages.
/**
 * It allocates the memory for the number of elements and calls
 * face_interfaces__srv__Partol_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Request__Sequence__init(face_interfaces__srv__Partol_Request__Sequence * array, size_t size);

/// Finalize array of srv/Partol messages.
/**
 * It calls
 * face_interfaces__srv__Partol_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Request__Sequence__fini(face_interfaces__srv__Partol_Request__Sequence * array);

/// Create array of srv/Partol messages.
/**
 * It allocates the memory for the array and calls
 * face_interfaces__srv__Partol_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
face_interfaces__srv__Partol_Request__Sequence *
face_interfaces__srv__Partol_Request__Sequence__create(size_t size);

/// Destroy array of srv/Partol messages.
/**
 * It calls
 * face_interfaces__srv__Partol_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Request__Sequence__destroy(face_interfaces__srv__Partol_Request__Sequence * array);

/// Check for srv/Partol message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Request__Sequence__are_equal(const face_interfaces__srv__Partol_Request__Sequence * lhs, const face_interfaces__srv__Partol_Request__Sequence * rhs);

/// Copy an array of srv/Partol messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Request__Sequence__copy(
  const face_interfaces__srv__Partol_Request__Sequence * input,
  face_interfaces__srv__Partol_Request__Sequence * output);

/// Initialize srv/Partol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * face_interfaces__srv__Partol_Response
 * )) before or use
 * face_interfaces__srv__Partol_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Response__init(face_interfaces__srv__Partol_Response * msg);

/// Finalize srv/Partol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Response__fini(face_interfaces__srv__Partol_Response * msg);

/// Create srv/Partol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * face_interfaces__srv__Partol_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
face_interfaces__srv__Partol_Response *
face_interfaces__srv__Partol_Response__create();

/// Destroy srv/Partol message.
/**
 * It calls
 * face_interfaces__srv__Partol_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Response__destroy(face_interfaces__srv__Partol_Response * msg);

/// Check for srv/Partol message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Response__are_equal(const face_interfaces__srv__Partol_Response * lhs, const face_interfaces__srv__Partol_Response * rhs);

/// Copy a srv/Partol message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Response__copy(
  const face_interfaces__srv__Partol_Response * input,
  face_interfaces__srv__Partol_Response * output);

/// Initialize array of srv/Partol messages.
/**
 * It allocates the memory for the number of elements and calls
 * face_interfaces__srv__Partol_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Response__Sequence__init(face_interfaces__srv__Partol_Response__Sequence * array, size_t size);

/// Finalize array of srv/Partol messages.
/**
 * It calls
 * face_interfaces__srv__Partol_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Response__Sequence__fini(face_interfaces__srv__Partol_Response__Sequence * array);

/// Create array of srv/Partol messages.
/**
 * It allocates the memory for the array and calls
 * face_interfaces__srv__Partol_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
face_interfaces__srv__Partol_Response__Sequence *
face_interfaces__srv__Partol_Response__Sequence__create(size_t size);

/// Destroy array of srv/Partol messages.
/**
 * It calls
 * face_interfaces__srv__Partol_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
void
face_interfaces__srv__Partol_Response__Sequence__destroy(face_interfaces__srv__Partol_Response__Sequence * array);

/// Check for srv/Partol message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Response__Sequence__are_equal(const face_interfaces__srv__Partol_Response__Sequence * lhs, const face_interfaces__srv__Partol_Response__Sequence * rhs);

/// Copy an array of srv/Partol messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_face_interfaces
bool
face_interfaces__srv__Partol_Response__Sequence__copy(
  const face_interfaces__srv__Partol_Response__Sequence * input,
  face_interfaces__srv__Partol_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FACE_INTERFACES__SRV__DETAIL__PARTOL__FUNCTIONS_H_
