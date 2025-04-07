#需要添加rcl_interfaces/srv/SetParameters
#导入
#from rcl_interfaces.srv import SetParameters
#from rcl_interfaces.msg import Parameter
#查看内容
#ros2 interface show rcl_interfaces/srv/SetParameters


import rclpy
from rclpy.node import Node
from face_interfaces.srv import FaceDetector
import face_recognition
import cv2
from ament_index_python.packages import  get_package_share_directory
import os
from cv_bridge import CvBridge
import time
from rcl_interfaces.srv import SetParameters
from rcl_interfaces.msg import Parameter,ParameterValue,ParameterType

class FaceDetectClientNode(Node):
  def __init__(self):
    super().__init__('face_detect_client_node')
    self.client = self.create_client(FaceDetector,'face_detect')
    self.bridge = CvBridge()
    self.default_image_path = os.path.join(get_package_share_directory('face_python_service'),
                                           'resource/default.jpg')
    self.get_logger().info(f'人脸检测客户端已启动')
    self.image = cv2.imread(self.default_image_path)
    
    
  def call_set_parameters(self,parameters):
    """调用服务修改参数值"""
    #创建一个客户端，等待服务上线
    update_param_client = self.create_client(SetParameters,'/face_detect_node/set_parameters')
    while update_param_client.wait_for_service(timeout_sec = 1.0) is False:
      self.get_logger().info(f'等待参数更新服务端上线')
    #创建request
    request = SetParameters.Request()
    request.parameters = parameters
    #调用服务端更新参数
    future = update_param_client.call_async(request)
    rclpy.spin_until_future_complete(self,future) #等待服务端返回响应
    response = future.result() # 获取响应
    return response
    
    
  def update_detect_model(self,model = 'hog'):
    """根据传入的model，构造parameters，然后调用call_set_parameters更新"""
    #1、创建参数对象
    param = Parameter()
    param.name = 'model'
    #2、赋值，创建param_value
    param_value = ParameterValue()
    param_value.string_value = model
    param_value.type = ParameterType.PARAMETER_STRING
    param.value = param_value
    #3请求更新参数
    response = self.call_set_parameters([param])
    for result in response.results:
      self.get_logger().info(f'设置参数结果：{result.successful} {result.reason}')
    
    
    
  def send_request(self):
    #判断服务端是否上线
    while self.client.wait_for_service(timeout_sec = 1.0) is False:
      self.get_logger().info(f'等待服务端上线')
    #构造Request
    request = FaceDetector.Request()
    request.image = self.bridge.cv2_to_imgmsg(self.image)
    #发送并等待处理完成
    #call_async创建一个服务请求，并且异步的获取结果
    future = self.client.call_async(request)#当前的future并没有包含响应结果，需要等待服务端处理完成才会把结果放到future中
    #while not future.done():
    #  time.sleep(1.0)  #休眠当前线程，等待服务处理完成===造成当前线程无法再接受来自服务端的返回，导致永远没有完成=》future.done无法返回true
    #rclpy.spin_until_future_complete(self,future) #等待服务端返回响应
    def result_callback(result_future):
      response = future.result() # 获取响应
      self.get_logger().info(f'接受到响应，共检测有{response.number}张人脸，耗时{response.use_time}s')
      #self.show_response(response)
      
    future.add_done_callback(result_callback)
    
    
  def show_response(self,response):
    for i in range(response.number):
      top = response.top[i]
      right = response.right[i]
      bottom = response.bottom[i]
      left = response.left[i]
      cv2.rectangle(self.image,(left,top),(right,bottom),(255,0,0),4)
    cv2.imshow('Face Detecte Result',self.image)
    cv2.waitKey(0) #也是阻塞的，会导致spin无法正常运行


def main():
  rclpy.init()
  node = FaceDetectClientNode()
  
  node.update_detect_model('hog')
  node.send_request()
  node.update_detect_model('cnn')
  node.send_request()
  
  rclpy.spin(node)
  rclpy.shutdown()