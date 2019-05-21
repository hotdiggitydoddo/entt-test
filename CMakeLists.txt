cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

project(entt-test)

include_directories(vendor/entt/src)

add_executable(entt-test main.cpp)