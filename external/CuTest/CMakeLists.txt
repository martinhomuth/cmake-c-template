
FetchContent_Declare(
  CuTest
  GIT_REPOSITORY https://github.com/martinhomuth/CuTest
  GIT_TAG v1.5
  )

FetchContent_MakeAvailable(cutest)
message(STATUS "CuTest made available")

