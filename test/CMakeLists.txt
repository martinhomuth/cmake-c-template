
FetchContent_GetProperties(CuTest)
set(test_files
  ${cutest_SOURCE_DIR}/CuTest.c
  ${cutest_SOURCE_DIR}/CuTest.h
  ${PROJECT_BINARY_DIR}/AllTests.c
  testmain.c
  )

set(src_files
  ${PROJECT_SOURCE_DIR}/src/test.c
  )

add_custom_target (
  AllTests
  ALL
  COMMAND bash ${cutest_SOURCE_DIR}/make-tests.sh ${PROJECT_SOURCE_DIR}/test/*.c > ${PROJECT_BINARY_DIR}/AllTests.c
  BYPRODUCTS ${PROJECT_BINARY_DIR}/AllTests.c
  )

add_executable(run_tests
  ${test_files}
  ${src_files}
  ${header_files}
  )

add_dependencies(run_tests AllTests)
target_include_directories(run_tests PRIVATE ${cutest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

add_test(test run_tests)


