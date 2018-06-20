cmake_minimum_required(VERSION 3.10)
project(lmis)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_subscriber test_Subscriber.cpp Subscriber.h)