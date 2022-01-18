from http.server import executable
import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    container = ComposableNodeContainer(
        name="two_nodes",
        namespace="",
        package="rclcpp_components",
        executable="component_container",
        composable_node_descriptions=[
            ComposableNode(
                package="ipc_demo", plugin="composition::Talker", name="talker"
            ),
            ComposableNode(
                package="ipc_demo", plugin="composition::Listener", name="listener"
            ),
        ],
        output="screen",
    )

    return launch.LaunchDescription([container])
