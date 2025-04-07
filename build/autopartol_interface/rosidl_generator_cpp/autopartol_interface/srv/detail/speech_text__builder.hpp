// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autopartol_interface:srv/SpeechText.idl
// generated code does not contain a copyright notice

#ifndef AUTOPARTOL_INTERFACE__SRV__DETAIL__SPEECH_TEXT__BUILDER_HPP_
#define AUTOPARTOL_INTERFACE__SRV__DETAIL__SPEECH_TEXT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autopartol_interface/srv/detail/speech_text__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autopartol_interface
{

namespace srv
{

namespace builder
{

class Init_SpeechText_Request_text
{
public:
  Init_SpeechText_Request_text()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopartol_interface::srv::SpeechText_Request text(::autopartol_interface::srv::SpeechText_Request::_text_type arg)
  {
    msg_.text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopartol_interface::srv::SpeechText_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopartol_interface::srv::SpeechText_Request>()
{
  return autopartol_interface::srv::builder::Init_SpeechText_Request_text();
}

}  // namespace autopartol_interface


namespace autopartol_interface
{

namespace srv
{

namespace builder
{

class Init_SpeechText_Response_result
{
public:
  Init_SpeechText_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopartol_interface::srv::SpeechText_Response result(::autopartol_interface::srv::SpeechText_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopartol_interface::srv::SpeechText_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopartol_interface::srv::SpeechText_Response>()
{
  return autopartol_interface::srv::builder::Init_SpeechText_Response_result();
}

}  // namespace autopartol_interface

#endif  // AUTOPARTOL_INTERFACE__SRV__DETAIL__SPEECH_TEXT__BUILDER_HPP_
