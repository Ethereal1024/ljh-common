from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='camera_calib',
            executable='decomposer',
            name='decomposer'
        ),
        Node(
            package='camera_calib',
            executable='calculator',
            name='calculator'
        ),
        Node(
            package='camera_calib',
            executable='marker',
            name='marker',
            parameters=['src/camera_calib/params.yml'] 
        ),
        Node(
            package='camera_calib',
            executable='captor',
            name='captor'
        ),
    ])