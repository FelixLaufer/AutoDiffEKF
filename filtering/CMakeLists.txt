add_library(filtering INTERFACE)
target_include_directories(filtering INTERFACE .)

target_link_libraries(filtering INTERFACE
  math
)