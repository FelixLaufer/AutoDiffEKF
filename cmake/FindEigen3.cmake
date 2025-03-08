if (NOT Eigen3_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    Eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE)
  set(EIGEN_BUILD_DOC OFF)
  set(EIGEN_BUILD_TESTING OFF)
  set(EIGEN_BUILD_PKGCONFIG OFF)
  set( OFF)
  FetchContent_MakeAvailable(Eigen)
endif()