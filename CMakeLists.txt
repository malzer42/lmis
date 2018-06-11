cmake_minimum_required(VERSION 3.10)
project(lmis)

set(CMAKE_CXX_STANDARD 17)

add_executable(lmis main.cpp Book.cpp Book.h Subscriber.cpp Subscriber.h Borrow.cpp Borrow.h Library.cpp Library.h)