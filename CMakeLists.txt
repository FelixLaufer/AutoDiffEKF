cmake_minimum_required(VERSION 3.2)

project(AutoDiffEKF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-fPIC")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories(.)

add_subdirectory(app)
add_subdirectory(math)
add_subdirectory(filtering)
add_subdirectory(plotting)