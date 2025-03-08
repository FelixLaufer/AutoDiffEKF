find_package(pybind11 REQUIRED)
find_package(matplotlibcpp17 REQUIRED)

add_library(plotting INTERFACE)
target_include_directories(plotting INTERFACE .)

target_link_libraries(plotting INTERFACE
  pybind11::pybind11
  matplotlibcpp17::matplotlibcpp17
  math
)