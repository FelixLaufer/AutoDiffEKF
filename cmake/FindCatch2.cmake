if (NOT autodiff_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    Catch2
    GIT_SHALLOW    TRUE
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        devel
  )
  set(CATCH_BUILD_TESTING OFF)
  set(CATCH_BUILD_EXAMPLES OFF)
  set(CATCH_BUILD_EXTRA_TESTS OFF)
  set(CATCH_BUILD_FUZZERS OFF)
  FetchContent_MakeAvailable(Catch2)
endif()