find_package(Eigen3 REQUIRED)
find_package(autodiff REQUIRED)

add_library(math INTERFACE)
target_include_directories(math INTERFACE .)

target_link_libraries(math INTERFACE
  Eigen3::Eigen
  autodiff::autodiff
)