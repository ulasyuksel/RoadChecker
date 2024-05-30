#ref: https://google.github.io/googletest/quickstart-cmake.html
#To build under unit/RoadChecker/ folder: 
#cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
#cd build
#make

#to run test:
#./RoadCheckerTest

#for coverage
#under folder run:
#lcov -c -d /path/to/gcda_files -o coverage.info
#genhtml -o coverage_out_html coverage.info --ignore-errors source

cmake_minimum_required(VERSION 3.14)
project(RoadCheckerTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${RoadCheckerTest_SOURCE_DIR}/../CodeCoverage.cmake)
append_coverage_compiler_flags()

include_directories(${RoadCheckerTest_SOURCE_DIR}/../../GPSModule)
include_directories(${RoadCheckerTest_SOURCE_DIR}/../../RoadChecker)
include_directories(${RoadCheckerTest_SOURCE_DIR}/../../AcceleroMeter)
include_directories(${RoadCheckerTest_SOURCE_DIR}/../../SpeedUnit)
include_directories(${RoadCheckerTest_SOURCE_DIR}/../../StateHandler)
include_directories(${RoadCheckerTest_SOURCE_DIR}/../mocks/)

# Set the path to Google Test source directory
set(GTEST_SOURCE_DIR "${RoadCheckerTest_SOURCE_DIR}/../../3pp/googletest-release-1.11.0/")

# Add Google Test to your project
add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/gtest)

# Include directories for Google Test headers
include_directories(${GTEST_SOURCE_DIR}/googletest/include)

enable_testing()

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB all_SRCS 
	"${RoadCheckerTest_SOURCE_DIR}/../mocks/MockAcceleroMeter.cc"
	"${RoadCheckerTest_SOURCE_DIR}/../mocks/MockGPSModule.cc"
	"${RoadCheckerTest_SOURCE_DIR}/../mocks/MockSpeedUnit.cc"
	"${RoadCheckerTest_SOURCE_DIR}/../mocks/MockStateHandler.cc"
	"${RoadCheckerTest_SOURCE_DIR}/../../GPSModule/GeoCoordinate.cc"
	"${RoadCheckerTest_SOURCE_DIR}/../../RoadChecker/RoadChecker.cc"
	)

add_executable(
  RoadCheckerTest
  RoadCheckerTest.cc
  ${all_SRCS}
)

target_link_libraries(
  RoadCheckerTest
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(RoadCheckerTest)

add_test(NAME RoadCheckerTest COMMAND RoadCheckerTest)
