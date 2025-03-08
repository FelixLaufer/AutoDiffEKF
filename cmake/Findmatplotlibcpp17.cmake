if (NOT matplotlibcpp17_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    matplotlibcpp17
    GIT_REPOSITORY https://github.com/soblin/matplotlibcpp17.git
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)
  FetchContent_MakeAvailable(matplotlibcpp17)
endif()