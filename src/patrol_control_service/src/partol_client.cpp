#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include "face_interfaces/srv/partol.hpp"

using namespace std::chrono_literals;//可以使用10s,100ms
using Partol = face_interfaces::srv::Partol;

class PartolClient: public rclcpp::Node
{
private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Client<Partol>::SharedPtr partol_client_;

public:
  PartolClient():Node("turtle_controller")
  {
    srand(time(NULL));//初始化随机数种子
    partol_client_ = this->create_client<Partol>("partol");
    timer_ = this->create_wall_timer(10s,[&]()->void{
    //检测服务端是否上线
    while(!(this->partol_client_->wait_for_service(1s)))
    {
        if(!rclcpp::ok())
        {
            RCLCPP_ERROR(this->get_logger(),"等待服务上线过程中,rclcpp挂了,我退下了");
            return;
        }
        RCLCPP_ERROR(this->get_logger(),"等待服务上线中.......");
    }
    //构造请求对象
    auto request = std::make_shared<Partol::Request>();
    request->target_x = rand() % 15;
    request->target_y = rand() % 15;
    RCLCPP_INFO(this->get_logger(),"准备好目标点%f,%f",request->target_x,request->target_y);
    //发送请求,async_send_request异步发送请求
    this->partol_client_->async_send_request(request,[&](rclcpp::Client<Partol>::SharedFuture result_future)->void{
        auto response = result_future.get();
        if(response->result == Partol::Response::SUCESS)
        {
            RCLCPP_INFO(this->get_logger(),"请求巡逻目标点成功");
        }
        if(response->result == Partol::Response::FAIL)
        {
            RCLCPP_INFO(this->get_logger(),"请求巡逻目标点失败");
        }
    });
    });
  };     
};

int main(int argc,char* argv[])
{
  rclcpp::init(argc,argv);
  auto node = std::make_shared<PartolClient>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}