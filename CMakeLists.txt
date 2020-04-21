cmake_minimum_required(VERSION 3.2)
project(freefly)
set(CMAKE_CXX_STANDARD 14)

include_directories(include lib/include vendor/include)
add_subdirectory(lib)
add_subdirectory(vendor)

add_executable(freefly main.cpp)
target_link_libraries(freefly Bluetooth bluetooth)