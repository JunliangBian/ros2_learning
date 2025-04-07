#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include "turtlesim/msg/pose.hpp"
#include "face_interfaces/srv/partol.hpp"

using namespace std::chrono_literals;
using Partol = face_interfaces::srv::Partol;

class TurtleControlNode: public rclcpp::Node
{
private:
  //发布者的智能指针
  rclcpp::Service<Partol>::SharedPtr partol_service;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
  
  double target_x_{1.0};
  double target_y_{1.0};
  double k_{1.0};//比例系数
  double max_speed_{3.0};//最大速度

public:
  explicit TurtleControlNode(const std::string& node_name):Node(node_name)
  {
    partol_service = this->create_service<Partol>("partol",[&](const Partol::Request::SharedPtr request,Partol::Response::SharedPtr response) -> void{
    if((0 < request->target_x && request -> target_x < 12.0f)&&
       (0 < request->target_y && request -> target_y < 12.0f)
      )
      {
        this->target_x_ = request ->target_x;
        this->target_y_ = request ->target_y;
        response->result = Partol::Response::SUCESS;
      }
      else
      {
        response->result = Partol::Response::FAIL;
      }
    });
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel",10);
    subscriber_ = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose",10,
      std::bind(&TurtleControlNode::on_pose_received,
                                     this,
                                     std::placeholders::_1));
  }

  //参数，收到数据的共享指针
  void on_pose_received(const turtlesim::msg::Pose::SharedPtr pose)
  {
    //1、获取当前的位置
    auto current_x = pose->x;
    auto current_y = pose->y;
    RCLCPP_INFO(get_logger(),"当前：x=%f,y=%f",current_x,current_y);
    
    //2、计算当前海龟位置跟目标位置之间的距离差和角度差
    auto distance = std::sqrt(
      (target_x_ - current_x)*(target_x_ - current_x)+
      (target_y_ - current_y)*(target_y_ - current_y));
    auto angle = std::atan2((target_y_ - current_y),(target_x_ - current_x))-pose->theta;
    
    //3、控制策略
    auto msg = geometry_msgs::msg::Twist();
    if(distance > 0.1)
    {
      if(fabs(angle)>0.2)
      {
        msg.angular.z = fabs(angle);
      }
      else
      {
        msg.linear.x = k_ * distance;
      }
    }
    //4、限制线速度最大值
    if( msg.linear.x > max_speed_)
    {
      msg.linear.x = max_speed_;
    }
    
    publisher_->publish(msg);
  }
       
};

int main(int argc,char* argv[])
{
  rclcpp::init(argc,argv);
  auto node = std::make_shared<TurtleControlNode>("turtle_control");
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}