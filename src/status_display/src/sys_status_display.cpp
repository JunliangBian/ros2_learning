#include <QApplication>
#include <QLabel>  //QT中的标签
#include <QString> // QT中的字符串
#include <rclcpp/rclcpp.hpp>
#include <status_interfaces/msg/system_status.hpp>

using SystemStatus = status_interfaces::msg::SystemStatus;

class SysStatusDisplay:public rclcpp::Node
{
private:
  rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
  QLabel *label_;
public:
  SysStatusDisplay():Node("sys_status_display")
  {
    label_ = new QLabel();
    subscriber_ = create_subscription<SystemStatus>("sys_status",10,[&]
    (const SystemStatus::SharedPtr msg) -> void{
      label_->setText(get_qstr_from_msg(msg));
    });
    label_->setText(get_qstr_from_msg(std::make_shared<SystemStatus>()));
    label_->show();
  };
  
  QString get_qstr_from_msg(const SystemStatus::SharedPtr msg)
  {
      std::stringstream show_str;
      show_str << "==================系统状态可视化==================\n"
              << "数据时间:\t" << msg->stamp.sec << " s\n"
              << "主机名称:\t" << msg->host_name << "\n"
              << "CPU使用率:\t" << msg->cpu_percent << "%\n"
              << "内存使用率:\t" << msg->memory_percent << "%\n"
              << "内存总大小:\t" << msg->memory_total << " MB\n"
              << "剩余内存:\t" << msg->memory_available << " MB\n"
              << "网络发送量:\t" << msg->net_sent << " MB\n"
              << "网络接收量:\t" << msg->net_recv << " MB\n"
              << "=============================================";
      // 强制 UTF-8 编码
      return QString::fromStdString(show_str.str());
  }
};

int main(int argc,char *argv[])
{
  rclcpp::init(argc,argv);
  QApplication app(argc,argv);
  auto node = std::make_shared<SysStatusDisplay>();
  std::thread spin_thread([&]() -> void
                          {
                            rclcpp::spin(node);//阻塞代码
                          });
  spin_thread.detach();
  app.exec();//执行应用
  return 0;
}