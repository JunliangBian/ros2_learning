#启动服务通信的服务端之后运行下面一行命令，观察
#ros2 service list -t 

#在回调函数detect_callback中加入回调函数进行参数更新

#修改自身节点的参数
# self.set_parameters([rclpy.Parameter('model',rclpy.Parameter.type.STRING,'cnn')])


import rclpy
from rclpy.node import Node
from face_interfaces.srv import FaceDetector
import face_recognition
import cv2
from ament_index_python.packages import  get_package_share_directory
import os
from cv_bridge import CvBridge
import time
from rcl_interfaces.msg import SetParametersResult

class FaceDetectNode(Node):
  def __init__(self):
    super().__init__('face_detect_node')
    self.service = self.create_service(FaceDetector,
                                       'face_detect',
                                       self.detect_callback)
    self.bridge = CvBridge()
    self.declare_parameter("number_of_times_to_upsample",1)
    self.declare_parameter("model",'hog')
    self.number_of_times_to_upsample = self.get_parameter('number_of_times_to_upsample').value
    self.model = self.get_parameter('model').value
    self.default_image_path = os.path.join(get_package_share_directory('face_python_service'),
                                           'resource/default.jpg')
    self.get_logger().info(f'人脸检测服务已经启动')
    self.add_on_set_parameters_callback(self.parameters_callback)
    #self.set_parameters([rclpy.Parameter('model',rclpy.Parameter.Type.STRING,'cnn')]) #设置自身节点参数的方法
    
  def parameters_callback(self,parameters):
    for parameter in parameters:
      self.get_logger().info(f'{parameter.name}->{parameter.value}')
      if parameter.name == 'number_of_times_to_upsample':
        self.number_of_times_to_upsample = parameter.value
      if parameter.name == 'model':
        self.model = parameter.value
    return SetParametersResult(successful=True)
        
        
  def detect_callback(self,request,response):
    if request.image.data:
      cv_image = self.bridge.imgmsg_to_cv2(request.image)
    else:
      cv_image = cv2.imread(self.default_image_path)
      self.get_logger().info(f'传入图像为空，使用默认图像')
    #cv_image已经时opencv格式的了
    start_time = time.time()
    self.get_logger().info(f'加载完成图像，开始检测')
    #检测人脸
    face_locations = face_recognition.face_locations(cv_image,
                                                   number_of_times_to_upsample = self.number_of_times_to_upsample,
                                                   model = self.model)
    response.use_time = time.time() - start_time
    response.number = len(face_locations)
    for top,right,bottom,left in face_locations:
      response.top.append(top)
      response.right.append(right)
      response.bottom.append(bottom)
      response.left.append(left)
    return response #必须返回response


def main():
  rclpy.init()
  node = FaceDetectNode()
  rclpy.spin(node)
  rclpy.shutdown()