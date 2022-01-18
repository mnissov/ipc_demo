#ifndef IPC_DEMO__TALKER_HPP_
#define IPC_DEMO__TALKER_HPP_

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/int16.hpp"

#include <iostream>

namespace composition {

class Talker : public rclcpp::Node {
 public:
  Talker(const rclcpp::NodeOptions &options = rclcpp::NodeOptions().use_intra_process_comms(true))
      : Node("ipc_talker", options) {
    pub_ = this->create_publisher<std_msgs::msg::Int16>("temp", 1);
    timer_ =
        this->create_wall_timer(std::chrono::seconds(1), std::bind(&Talker::timer_callback, this));
  }

 private:
  void timer_callback(void) {
    std_msgs::msg::Int16::UniquePtr msg(new std_msgs::msg::Int16());

    msg->data = count_;
    RCLCPP_INFO(this->get_logger(), "Count: %d\tAddr: %p", msg->data, msg.get());
    count_++;

    pub_->publish(std::move(msg));
  }

  // std_msgs::msg::Int16::UniquePtr count_;
  int count_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr pub_;
};
}  // namespace composition

#endif  // IPC_DEMO__TALKER_HPP_