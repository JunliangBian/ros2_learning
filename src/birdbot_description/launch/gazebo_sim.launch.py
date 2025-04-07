import launch
import launch.event_handlers
import launch_ros
from ament_index_python.packages import get_package_share_directory
import os
import launch_ros.parameter_descriptions

def generate_launch_description():
  #获取默认的路径
  urdf_package_path = get_package_share_directory('birdbot_description')
  default_xacro_path = os.path.join(urdf_package_path,'urdf','birdbot/birdbot.urdf.xacro')
  default_gazebo_config_path = os.path.join(urdf_package_path,'world','custom_room2.world')
  #声明一个urdf目录的参数，方便修改
  action_declare_arg_mode_path = launch.actions.DeclareLaunchArgument(
    name = 'model',default_value = default_xacro_path,description='加载的模型文件路径'
  )
  # 通过文件路径，获取内容，并转换成参数值对象，以供传入robot_state_publisher    
  #  # 安全读取URDF文件内容
#   with open(default_urdf_path, 'r') as f:
#     substitutions_command_result = f.read()  
  
  substitutions_command_result = launch.substitutions.Command(['xacro ',launch.substitutions.LaunchConfiguration('model')])
  robot_description_value = launch_ros.parameter_descriptions.ParameterValue(substitutions_command_result,value_type=str)
  
  action_robot_state_publisher = launch_ros.actions.Node(
    package = 'robot_state_publisher',
    executable = 'robot_state_publisher',
    parameters = [{'robot_description':robot_description_value}]#传递到节点
  )

  # 通过 IncludeLaunchDescription 包含另外一个 launch 文件
  action_launch_gazebo = launch.actions.IncludeLaunchDescription(
    launch_description_source=([get_package_share_directory('gazebo_ros'),'/launch/','/gazebo.launch.py']),
    launch_arguments=[('world',default_gazebo_config_path),('verbose','true')]
  )
  # 请求 Gazebo 加载机器人
  action_spwan_entity = launch_ros.actions.Node(
    package="gazebo_ros",
    executable="spawn_entity.py",
    arguments=['-topic','/robot_description','-entity','birdbot']
  )
  
  # 加载并激活 birdbot_joint_state_broadcaster 控制器
  load_joint_state_controller = launch.actions.ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active','birdbot_joint_state_broadcaster'],
        output='screen'
    )

  # 加载并激活 birdbot_effort_controller 控制器 ,,,,两个控制器使用一个
  load_birdbot_effort_controller = launch.actions.ExecuteProcess(
      cmd=['ros2', 'control', 'load_controller', '--set-state', 'active','birdbot_effort_controller'], 
      output='screen')
  
  load_birdbot_diff_drive_controller = launch.actions.ExecuteProcess(
      cmd=['ros2', 'control', 'load_controller', '--set-state', 'active','birdbot_diff_drive_controller'], 
      output='screen')
  

  return launch.LaunchDescription([
    action_declare_arg_mode_path,
    action_robot_state_publisher,
    action_launch_gazebo,
    action_spwan_entity,
    # 事件动作，当加载机器人结束后执行 
    launch.actions.RegisterEventHandler(
      event_handler= launch.event_handlers.OnProcessExit(
        target_action=action_spwan_entity,
        on_exit=[load_joint_state_controller],
      )
    ),

    launch.actions.RegisterEventHandler(
      event_handler= launch.event_handlers.OnProcessExit(
        target_action=load_joint_state_controller,
        on_exit=[load_birdbot_diff_drive_controller],
      )
    )

  ])

