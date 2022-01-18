#ifndef IPC_DEMO__LISTENER_HPP_
#define IPC_DEMO__LISTENER_HPP_

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/int16.hpp"

#include <iostream>

namespace composition {

class Listener : public rclcpp::Node {
 public:
  Listener(const rclcpp::NodeOptions &options = rclcpp::NodeOptions().use_intra_process_comms(true))
      : Node("ipc_listener", options) {
    sub_ = this->create_subscription<std_msgs::msg::Int16>(
        "temp", 1, std::bind(&Listener::sub_callback, this, std::placeholders::_1));
  }

 private:
  void sub_callback(const std_msgs::msg::Int16::UniquePtr msg) {
    RCLCPP_INFO(this->get_logger(), "Count: %d\tAddr: %p", msg->data, msg.get());
  }

  rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr sub_;
};

}  // namespace composition

#endif  // IPC_DEMO__LISTENER_HPP_