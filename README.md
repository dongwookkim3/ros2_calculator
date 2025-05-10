# 🤖 ROS2 C++ Calculator Package

A beginner-friendly ROS2 package written in C++ that performs basic arithmetic operations.  
It demonstrates ROS2 concepts such as publishers, subscribers, and inter-node communication.

---

## 📦 Package Overview

This package contains **four nodes**:

- `input_value1_node` — Publishes the first integer
- `input_value2_node` — Publishes the second integer
- `operator_node` — Publishes the operator (`+`, `-`, `*`, `/`)
- `calculator_node` — Subscribes to all above and publishes the result

---

## 🧠 Node Architecture

```
[input_value1_node]    [input_value2_node]    [operator_node]
        |                     |                    |
        +----------+----------+----------> [calculator_node]
```

---

## 🗂️ Directory Structure

```
ros2_calculator_cpp/
├── src/
│   ├── input_value1_node.cpp
│   ├── input_value2_node.cpp
│   ├── operator_node.cpp
│   └── calculator_node.cpp
├── launch/
│   └── calculator.launch.py
├── CMakeLists.txt
├── package.xml
└── README.md
```

---

## 🚀 Build & Run

### ✅ Build

```bash
cd ~/ros2_ws
colcon build --packages-select ros2_calculator_cpp
source install/setup.bash
```

### ▶️ Run Individual Nodes

```bash
ros2 run ros2_calculator_cpp input_value1_node
ros2 run ros2_calculator_cpp input_value2_node
ros2 run ros2_calculator_cpp operator_node
ros2 run ros2_calculator_cpp calculator_node
```

### 📦 Or Run All with Launch File

```bash
ros2 launch ros2_calculator_cpp calculator.launch.py
```

---

## 🛰️ Topics

| Topic       | Type                    | Description                  |
|-------------|-------------------------|------------------------------|
| `/value1`   | `std_msgs/msg/Int32`    | First input integer          |
| `/value2`   | `std_msgs/msg/Int32`    | Second input integer         |
| `/operator` | `std_msgs/msg/String`   | Operator (`+`, `-`, `*`, `/`)|
| `/result`   | `std_msgs/msg/Float32`  | Result of the calculation    |

---

## ⚙️ Dependencies

- ROS 2 **Humble Hawksbill**
- `std_msgs`

---

## 👨‍💻 Author

Made with ❤️ by **[Your Name]**  
Learning ROS2 with C++ through hands-on mini-projects!