#include "rclcpp/rclcpp.hpp"

#include "ipc_demo/listener.hpp"
#include "ipc_demo/talker.hpp"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  /* both work */
  // rclcpp::executors::SingleThreadedExecutor executor;
  rclcpp::executors::MultiThreadedExecutor executor;

  auto talker = std::make_shared<composition::Talker>();
  auto listener = std::make_shared<composition::Listener>();

  executor.add_node(talker);
  executor.add_node(listener);
  executor.spin();

  rclcpp::shutdown();
  return 0;
}