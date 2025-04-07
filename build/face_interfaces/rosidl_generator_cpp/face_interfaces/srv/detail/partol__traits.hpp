// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from face_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice

#ifndef FACE_INTERFACES__SRV__DETAIL__PARTOL__TRAITS_HPP_
#define FACE_INTERFACES__SRV__DETAIL__PARTOL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "face_interfaces/srv/detail/partol__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace face_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Partol_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_x
  {
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << ", ";
  }

  // member: target_y
  {
    out << "target_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Partol_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << "\n";
  }

  // member: target_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Partol_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace face_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use face_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const face_interfaces::srv::Partol_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  face_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use face_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const face_interfaces::srv::Partol_Request & msg)
{
  return face_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<face_interfaces::srv::Partol_Request>()
{
  return "face_interfaces::srv::Partol_Request";
}

template<>
inline const char * name<face_interfaces::srv::Partol_Request>()
{
  return "face_interfaces/srv/Partol_Request";
}

template<>
struct has_fixed_size<face_interfaces::srv::Partol_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<face_interfaces::srv::Partol_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<face_interfaces::srv::Partol_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace face_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Partol_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Partol_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Partol_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace face_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use face_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const face_interfaces::srv::Partol_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  face_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use face_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const face_interfaces::srv::Partol_Response & msg)
{
  return face_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<face_interfaces::srv::Partol_Response>()
{
  return "face_interfaces::srv::Partol_Response";
}

template<>
inline const char * name<face_interfaces::srv::Partol_Response>()
{
  return "face_interfaces/srv/Partol_Response";
}

template<>
struct has_fixed_size<face_interfaces::srv::Partol_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<face_interfaces::srv::Partol_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<face_interfaces::srv::Partol_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<face_interfaces::srv::Partol>()
{
  return "face_interfaces::srv::Partol";
}

template<>
inline const char * name<face_interfaces::srv::Partol>()
{
  return "face_interfaces/srv/Partol";
}

template<>
struct has_fixed_size<face_interfaces::srv::Partol>
  : std::integral_constant<
    bool,
    has_fixed_size<face_interfaces::srv::Partol_Request>::value &&
    has_fixed_size<face_interfaces::srv::Partol_Response>::value
  >
{
};

template<>
struct has_bounded_size<face_interfaces::srv::Partol>
  : std::integral_constant<
    bool,
    has_bounded_size<face_interfaces::srv::Partol_Request>::value &&
    has_bounded_size<face_interfaces::srv::Partol_Response>::value
  >
{
};

template<>
struct is_service<face_interfaces::srv::Partol>
  : std::true_type
{
};

template<>
struct is_service_request<face_interfaces::srv::Partol_Request>
  : std::true_type
{
};

template<>
struct is_service_response<face_interfaces::srv::Partol_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FACE_INTERFACES__SRV__DETAIL__PARTOL__TRAITS_HPP_
