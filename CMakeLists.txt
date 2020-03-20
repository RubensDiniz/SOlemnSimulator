cmake_minimum_required(VERSION 3.15)
project(SOlemnSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(SOlemnSimulator Simulator.cpp Process.cpp Scheduler.cpp Core.cpp Kernel.cpp CPU.cpp)