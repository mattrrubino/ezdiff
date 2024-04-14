cmake_minimum_required(VERSION 3.16)

project(EZD
  VERSION 1.0.0
  DESCRIPTION "A simple automatic differentiation engine."
  HOMEPAGE_URL "https://mattrrubino.github.io/ezdiff"
  LANGUAGES CXX)

# Includes
include(CTest)
include(GoogleTest)

# Create library
add_library(ezd src/ezd.cpp src/node.cpp src/arith.cpp)
set_target_properties(ezd PROPERTIES CXX_STANDARD 17)
target_include_directories(ezd PUBLIC include)

# Create install target
install(TARGETS ezd DESTINATION lib)
install(FILES include/ezd.hpp include/node.hpp include/arith.hpp DESTINATION include/ezd)

# Create tests
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

