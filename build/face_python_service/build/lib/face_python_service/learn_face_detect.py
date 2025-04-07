import face_recognition
import cv2
from ament_index_python.packages import get_package_share_directory #获取功能包share目录绝对路径
import os

def main():
  # 获取图片的真实目录
  default_image_path = os.path.join(get_package_share_directory('face_python_service'),'resource/default.jpg')
  print(f'图片的真实路径：{default_image_path}')
  #使用cv2加载图片
  image = cv2.imread(default_image_path)
  #检测人脸
  face_locations = face_recognition.face_locations(image,
                                                   number_of_times_to_upsample = 1,
                                                   model = 'hog')
  #绘制人脸框
  for top,right,bottom,left in face_locations:
    cv2.rectangle(image,(left,top),(right,bottom),(255,0,0),4)
  #结果显示
  cv2.imshow('Face Detecte Result',image)
  cv2.waitKey(0)
  
  