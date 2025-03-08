if (NOT autodiff_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    autodiff
    GIT_REPOSITORY https://github.com/autodiff/autodiff.git
    GIT_TAG v1.1.2
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)
  set(AUTODIFF_BUILD_TESTS OFF)
  set(AUTODIFF_BUILD_PYTHON OFF)
  set(AUTODIFF_BUILD_EXAMPLES OFF)
  set(AUTODIFF_BUILD_DOCS OFF)
  FetchContent_MakeAvailable(autodiff)
endif()