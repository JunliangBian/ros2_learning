#实现这样的功能
#ros2 launch xxx actions.launch.py rqt=False
#ros2 launch xxx actions.launch.py rqt=True
##############################################################
import launch
import launch_ros
import launch.launch_description_sources
from ament_index_python.packages import get_package_share_directory #通过功能包名字包含share目录

def generate_launch_description():
 
  multisim_launch_path = [get_package_share_directory('turtlesim'),'/launch/','multisim.launch.py']
  action_declare_startup_rqt = launch.actions.DeclareLaunchArgument('startup_rqt',default_value='False')
  startup_rqt = launch.substitutions.LaunchConfiguration('startup_rqt',default="False")
   # 动作1、启动其他launch
  action_include_launch = launch.actions.IncludeLaunchDescription(
    launch.launch_description_sources.PythonLaunchDescriptionSource(
      multisim_launch_path
    )
  )
  
  # 动作2、打印数据
  action_log_info = launch.actions.LogInfo(msg = str(multisim_launch_path))
  

  # 动作3、执行进程，其实就是执行一个命令行，ros2 topic list
  # if startup_rqt:
  # run rqt
  action_topic_list = launch.actions.ExecuteProcess(
    condition = launch.conditions.IfCondition(startup_rqt),
    cmd=['rqt']
  )
  
  # 动作4组织动作成组，把多个动作放到一组
  action_group = launch.actions.GroupAction([
    # 动作5，定时器
    launch.actions.TimerAction(period=2.0,actions=[action_include_launch]),
    launch.actions.TimerAction(period=4.0,actions=[action_topic_list])
  ])
  
  
  return launch.LaunchDescription([
    #action动作
    action_declare_startup_rqt,
    action_log_info,
    action_group
  ])


