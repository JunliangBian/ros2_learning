// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from face_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice
#include "face_interfaces/srv/detail/partol__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
face_interfaces__srv__Partol_Request__init(face_interfaces__srv__Partol_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target_x
  // target_y
  return true;
}

void
face_interfaces__srv__Partol_Request__fini(face_interfaces__srv__Partol_Request * msg)
{
  if (!msg) {
    return;
  }
  // target_x
  // target_y
}

bool
face_interfaces__srv__Partol_Request__are_equal(const face_interfaces__srv__Partol_Request * lhs, const face_interfaces__srv__Partol_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_x
  if (lhs->target_x != rhs->target_x) {
    return false;
  }
  // target_y
  if (lhs->target_y != rhs->target_y) {
    return false;
  }
  return true;
}

bool
face_interfaces__srv__Partol_Request__copy(
  const face_interfaces__srv__Partol_Request * input,
  face_interfaces__srv__Partol_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // target_x
  output->target_x = input->target_x;
  // target_y
  output->target_y = input->target_y;
  return true;
}

face_interfaces__srv__Partol_Request *
face_interfaces__srv__Partol_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  face_interfaces__srv__Partol_Request * msg = (face_interfaces__srv__Partol_Request *)allocator.allocate(sizeof(face_interfaces__srv__Partol_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(face_interfaces__srv__Partol_Request));
  bool success = face_interfaces__srv__Partol_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
face_interfaces__srv__Partol_Request__destroy(face_interfaces__srv__Partol_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    face_interfaces__srv__Partol_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
face_interfaces__srv__Partol_Request__Sequence__init(face_interfaces__srv__Partol_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  face_interfaces__srv__Partol_Request * data = NULL;

  if (size) {
    data = (face_interfaces__srv__Partol_Request *)allocator.zero_allocate(size, sizeof(face_interfaces__srv__Partol_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = face_interfaces__srv__Partol_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        face_interfaces__srv__Partol_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
face_interfaces__srv__Partol_Request__Sequence__fini(face_interfaces__srv__Partol_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      face_interfaces__srv__Partol_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

face_interfaces__srv__Partol_Request__Sequence *
face_interfaces__srv__Partol_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  face_interfaces__srv__Partol_Request__Sequence * array = (face_interfaces__srv__Partol_Request__Sequence *)allocator.allocate(sizeof(face_interfaces__srv__Partol_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = face_interfaces__srv__Partol_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
face_interfaces__srv__Partol_Request__Sequence__destroy(face_interfaces__srv__Partol_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    face_interfaces__srv__Partol_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
face_interfaces__srv__Partol_Request__Sequence__are_equal(const face_interfaces__srv__Partol_Request__Sequence * lhs, const face_interfaces__srv__Partol_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!face_interfaces__srv__Partol_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
face_interfaces__srv__Partol_Request__Sequence__copy(
  const face_interfaces__srv__Partol_Request__Sequence * input,
  face_interfaces__srv__Partol_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(face_interfaces__srv__Partol_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    face_interfaces__srv__Partol_Request * data =
      (face_interfaces__srv__Partol_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!face_interfaces__srv__Partol_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          face_interfaces__srv__Partol_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!face_interfaces__srv__Partol_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
face_interfaces__srv__Partol_Response__init(face_interfaces__srv__Partol_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
face_interfaces__srv__Partol_Response__fini(face_interfaces__srv__Partol_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
face_interfaces__srv__Partol_Response__are_equal(const face_interfaces__srv__Partol_Response * lhs, const face_interfaces__srv__Partol_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
face_interfaces__srv__Partol_Response__copy(
  const face_interfaces__srv__Partol_Response * input,
  face_interfaces__srv__Partol_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

face_interfaces__srv__Partol_Response *
face_interfaces__srv__Partol_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  face_interfaces__srv__Partol_Response * msg = (face_interfaces__srv__Partol_Response *)allocator.allocate(sizeof(face_interfaces__srv__Partol_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(face_interfaces__srv__Partol_Response));
  bool success = face_interfaces__srv__Partol_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
face_interfaces__srv__Partol_Response__destroy(face_interfaces__srv__Partol_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    face_interfaces__srv__Partol_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
face_interfaces__srv__Partol_Response__Sequence__init(face_interfaces__srv__Partol_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  face_interfaces__srv__Partol_Response * data = NULL;

  if (size) {
    data = (face_interfaces__srv__Partol_Response *)allocator.zero_allocate(size, sizeof(face_interfaces__srv__Partol_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = face_interfaces__srv__Partol_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        face_interfaces__srv__Partol_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
face_interfaces__srv__Partol_Response__Sequence__fini(face_interfaces__srv__Partol_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      face_interfaces__srv__Partol_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

face_interfaces__srv__Partol_Response__Sequence *
face_interfaces__srv__Partol_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  face_interfaces__srv__Partol_Response__Sequence * array = (face_interfaces__srv__Partol_Response__Sequence *)allocator.allocate(sizeof(face_interfaces__srv__Partol_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = face_interfaces__srv__Partol_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
face_interfaces__srv__Partol_Response__Sequence__destroy(face_interfaces__srv__Partol_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    face_interfaces__srv__Partol_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
face_interfaces__srv__Partol_Response__Sequence__are_equal(const face_interfaces__srv__Partol_Response__Sequence * lhs, const face_interfaces__srv__Partol_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!face_interfaces__srv__Partol_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
face_interfaces__srv__Partol_Response__Sequence__copy(
  const face_interfaces__srv__Partol_Response__Sequence * input,
  face_interfaces__srv__Partol_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(face_interfaces__srv__Partol_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    face_interfaces__srv__Partol_Response * data =
      (face_interfaces__srv__Partol_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!face_interfaces__srv__Partol_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          face_interfaces__srv__Partol_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!face_interfaces__srv__Partol_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
