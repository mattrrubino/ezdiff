# Fetch GTest
include(FetchContent)
FetchContent_Declare(
  gtest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(gtest)

# Create test executable
add_executable(ezd_test main.cpp test_arith.cpp test_reg.cpp)
set_target_properties(ezd_test PROPERTIES CXX_STANDARD 17)
target_link_libraries(ezd_test ezd GTest::gtest_main)

# Create test
gtest_add_tests(TARGET ezd_test)

