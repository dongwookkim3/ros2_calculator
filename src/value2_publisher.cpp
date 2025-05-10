#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("value2_publisher");
    auto publisher = node->create_publisher<std_msgs::msg::Int32>("value2", 10);

    int input;
    std::cout << "Enter value2: ";
    std::cin >> input;

    std_msgs::msg::Int32 msg;
    msg.data = input;
    publisher->publish(msg);

    rclcpp::shutdown();
    return 0;
}
