cmake_minimum_required(VERSION 3.8)
project(thruster_load_test)

set(CMAKE_CXX_STANDARD 11)

set(THRUSTERLOADTEST_SRCS include/usbscale.h src/thruster_load_test.cpp src/usbscale.cpp)

add_executable(thruster_load_test ${THRUSTERLOADTEST_SRCS})
# Used internally by usbscale
add_executable(lusb src/lsusb.c include/scales.h)

target_link_libraries(thruster_load_test m usb-1.0)
