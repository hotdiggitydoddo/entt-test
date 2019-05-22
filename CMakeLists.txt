cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

project(entt-test)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(vendor/raylib)

include_directories(vendor/entt/src)
include_directories(vendor/raylib/src)

add_executable(entt-test src/main.cpp src/Engine/ResourceManager.h src/Engine/ResourceManager.cpp)

target_link_libraries(entt-test raylib)
