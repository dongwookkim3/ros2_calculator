cmake_minimum_required(VERSION 3.8)
project(ros2_calcultor)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

add_executable(value1_publisher src/value1_publisher.cpp)
ament_target_dependencies(value1_publisher rclcpp std_msgs)

add_executable(value2_publisher src/value2_publisher.cpp)
ament_target_dependencies(value2_publisher rclcpp std_msgs)

add_executable(operator_publisher src/operator_publisher.cpp)
ament_target_dependencies(operator_publisher rclcpp std_msgs)

add_executable(calculator_node src/calculator_node.cpp)
ament_target_dependencies(calculator_node rclcpp std_msgs)

install(TARGETS
  value1_publisher
  value2_publisher
  operator_publisher
  calculator_node
  DESTINATION lib/${PROJECT_NAME})