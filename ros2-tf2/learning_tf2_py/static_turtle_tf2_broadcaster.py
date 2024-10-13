import sys
from geometry_msgs.msg import TransformStamped

import rclpy
from rclpy.node import Node

from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster

import tf_transformations

class StaticFramePublisher(Node):
    
    def __init__(self, transformation):
        super().__init__('static_turtle_tf2_broadcaster')
        self._tf_publisher = StaticTransformBroadcaster(self)
        self.make_transforms(transformation)
        
    def make_transforms(self, transformation):
        static_tfStamped = TransformStamped()
        static_tfStamped.header.stamp = self.get_clock().now().to_msg()
        static_tfStamped.header.frame_id = 'world'
        static_tfStamped.child_frame_id = sys.argv[1]
        
        static_tfStamped.transform.translation.x = float(sys.argv[2])
        static_tfStamped.transform.translation.y = float(sys.argv[3])
        static_tfStamped.transform.translation.z = float(sys.argv[4])
        
        quat = tf_transformations.quaternion_from_euler(
            float(sys.argv[5]), float(sys.argv[6]), float(sys.argv[7]) 
        )
        static_tfStamped.transform.rotation.x = quat[0]
        static_tfStamped.transform.rotation.y = quat[1]
        static_tfStamped.transform.rotation.z = quat[2]
        static_tfStamped.transform.rotation.w = quat[3]
        
        self._tf_publisher.sendTransform(static_tfStamped)
        

def main():
    logger = rclpy.logging.get_logger('logger')
    
    if len(sys.argv) < 8:
        logger.info('Invalid number of parameters. Usage: \n'
                    '$ ros2 run learning_tf2_py static_turtle_tf2_broadcaster'
                    'child_frame_name x y z roll pitch yaw')
        sys.exit(0)
    else:
        if sys.argv[1] == 'world':
            logger.info('Your static turtle name cannot be "world"')
            sys.exit(0)
            
    rclpy.init()
    node = StaticFramePublisher(sys.argv)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    
    rclpy.shutdown()