#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"

class CalculatorNode : public rclcpp::Node {
public:
    CalculatorNode() : Node("calculator_node"), value1_(0), value2_(0), operator_received_(false), value1_received_(false), value2_received_(false) {
        sub1_ = this->create_subscription<std_msgs::msg::Int32>(
            "value1", 10, [this](std_msgs::msg::Int32::SharedPtr msg) {
                value1_ = msg->data;
                value1_received_ = true;
                calculate();
            });

        sub2_ = this->create_subscription<std_msgs::msg::Int32>(
            "value2", 10, [this](std_msgs::msg::Int32::SharedPtr msg) {
                value2_ = msg->data;
                value2_received_ = true;
                calculate();
            });

        sub_op_ = this->create_subscription<std_msgs::msg::String>(
            "operator", 10, [this](std_msgs::msg::String::SharedPtr msg) {
                op_ = msg->data;
                operator_received_ = true;
                calculate();
            });
    }

private:
    void calculate() {
        if (!value1_received_ || !value2_received_ || !operator_received_) return;

        double result = 0.0;
        bool valid = true;

        if (op_ == "+") result = value1_ + value2_;
        else if (op_ == "-") result = value1_ - value2_;
        else if (op_ == "*") result = value1_ * value2_;
        else if (op_ == "/") {
            if (value2_ != 0) result = static_cast<double>(value1_) / value2_;
            else {
                RCLCPP_ERROR(this->get_logger(), "Cannot divide by zero.");
                valid = false;
            }
        } else {
            RCLCPP_ERROR(this->get_logger(), "Invalid operator.");
            valid = false;
        }

        if (valid) {
            RCLCPP_INFO(this->get_logger(), "Result: %.3f", result);
        }

        value1_received_ = value2_received_ = operator_received_ = false;
    }

    int value1_, value2_;
    std::string op_;
    bool value1_received_, value2_received_, operator_received_;

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub1_, sub2_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_op_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CalculatorNode>());
    rclcpp::shutdown();
    return 0;
}
