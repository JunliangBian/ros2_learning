// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from face_interfaces:srv/Partol.idl
// generated code does not contain a copyright notice

#ifndef FACE_INTERFACES__SRV__DETAIL__PARTOL__BUILDER_HPP_
#define FACE_INTERFACES__SRV__DETAIL__PARTOL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "face_interfaces/srv/detail/partol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace face_interfaces
{

namespace srv
{

namespace builder
{

class Init_Partol_Request_target_y
{
public:
  explicit Init_Partol_Request_target_y(::face_interfaces::srv::Partol_Request & msg)
  : msg_(msg)
  {}
  ::face_interfaces::srv::Partol_Request target_y(::face_interfaces::srv::Partol_Request::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::face_interfaces::srv::Partol_Request msg_;
};

class Init_Partol_Request_target_x
{
public:
  Init_Partol_Request_target_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Partol_Request_target_y target_x(::face_interfaces::srv::Partol_Request::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_Partol_Request_target_y(msg_);
  }

private:
  ::face_interfaces::srv::Partol_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::face_interfaces::srv::Partol_Request>()
{
  return face_interfaces::srv::builder::Init_Partol_Request_target_x();
}

}  // namespace face_interfaces


namespace face_interfaces
{

namespace srv
{

namespace builder
{

class Init_Partol_Response_result
{
public:
  Init_Partol_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::face_interfaces::srv::Partol_Response result(::face_interfaces::srv::Partol_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::face_interfaces::srv::Partol_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::face_interfaces::srv::Partol_Response>()
{
  return face_interfaces::srv::builder::Init_Partol_Response_result();
}

}  // namespace face_interfaces

#endif  // FACE_INTERFACES__SRV__DETAIL__PARTOL__BUILDER_HPP_
