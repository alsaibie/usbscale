cmake_minimum_required(VERSION 3.8)
project(usbscale)
set(CMAKE_CXX_STANDARD 11)
add_executable(usbscale usbscale.c scales.h)
add_executable(lusb lsusb.c scales.h )
target_link_libraries(usbscale m usb-1.0)
