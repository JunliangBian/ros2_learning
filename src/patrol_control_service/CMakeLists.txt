cmake_minimum_required(VERSION 3.8)
project(patrol_control_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(face_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(turtle_control src/turtle_control.cpp) #添加可执行文件
add_executable(turtle_control2 src/turtle_control2.cpp) #添加可执行文件
add_executable(turtle_control3 src/turtle_control3.cpp) #添加可执行文件
add_executable(partol_client src/partol_client.cpp) 
add_executable(partol_client2 src/partol_client2.cpp) 
ament_target_dependencies(turtle_control face_interfaces rclcpp geometry_msgs turtlesim) #添加依赖
ament_target_dependencies(turtle_control2 face_interfaces rclcpp geometry_msgs turtlesim) #添加依赖
ament_target_dependencies(turtle_control3 face_interfaces rclcpp geometry_msgs turtlesim) #添加依赖

ament_target_dependencies(partol_client face_interfaces rclcpp)
ament_target_dependencies(partol_client2 face_interfaces rclcpp)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
# 安装拷贝到install目录下
install(TARGETS turtle_control partol_client turtle_control2 turtle_control3 partol_client2
  DESTINATION lib/${PROJECT_NAME}
)
ament_package()
