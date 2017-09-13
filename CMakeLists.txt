cmake_minimum_required(VERSION 3.8)
project(usbscale)
set(CMAKE_CXX_STANDARD 11)
set(SRCS lsusb.c
         usbscale.c)
add_executable(usbscale usbscale.c)
add_executable(lusb lsusb.c scales.h )
target_link_libraries(usbscale m usb-1.0)
