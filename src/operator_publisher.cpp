#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("operator_publisher");
    auto publisher = node->create_publisher<std_msgs::msg::String>("operator", 10);

    std::string op;
    std::cout << "Enter operator (+ - * /): ";
    std::cin >> op;

    std_msgs::msg::String msg;
    msg.data = op;
    publisher->publish(msg);

    rclcpp::shutdown();
    return 0;
}
