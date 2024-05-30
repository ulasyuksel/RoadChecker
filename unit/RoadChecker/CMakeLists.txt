#ref: https://google.github.io/googletest/quickstart-cmake.html
#To build under unit/RoadChecker/ folder: 
#cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
#cmake --build build --config Debug

#to run test:
#./RoadCheckerTest

#for coverage
#under folder run:
#lcov -c -d /path/to/gcda_files -o coverage.info
#genhtml -o coverage_out_html coverage.info --ignore-errors source

#or 

#cmake --build build --config Debug --target RoadCheckerTestCoverage
#if gcovr is installed via: sudo apt install gcovr

cmake_minimum_required(VERSION 3.14)
project(RoadCheckerTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_SOURCE_DIR}/../CodeCoverage.cmake)
append_coverage_compiler_flags()

include_directories(${CMAKE_SOURCE_DIR}/../../GPSModule)
include_directories(${CMAKE_SOURCE_DIR}/../../RoadChecker)
include_directories(${CMAKE_SOURCE_DIR}/../../AcceleroMeter)
include_directories(${CMAKE_SOURCE_DIR}/../../SpeedUnit)
include_directories(${CMAKE_SOURCE_DIR}/../../StateHandler)
include_directories(${CMAKE_SOURCE_DIR}/../mocks/)

# Set the path to Google Test source directory
set(GTEST_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../../3pp/googletest-release-1.11.0/")

# Add Google Test to your project
add_subdirectory(${GTEST_SOURCE_DIR} ${CMAKE_BINARY_DIR}/gtest)

# Include directories for Google Test headers
include_directories(${GTEST_SOURCE_DIR}/googletest/include)

enable_testing()

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB all_SRCS 
	"${CMAKE_SOURCE_DIR}/../mocks/MockAcceleroMeter.cc"
	"${CMAKE_SOURCE_DIR}/../mocks/MockGPSModule.cc"
	"${CMAKE_SOURCE_DIR}/../mocks/MockSpeedUnit.cc"
	"${CMAKE_SOURCE_DIR}/../mocks/MockStateHandler.cc"
	"${CMAKE_SOURCE_DIR}/../../GPSModule/GeoCoordinate.cc"
	"${CMAKE_SOURCE_DIR}/../../RoadChecker/RoadChecker.cc"
	)

add_executable(
  ${CMAKE_PROJECT_NAME}
  ${CMAKE_PROJECT_NAME}.cc
  ${all_SRCS}
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME})

add_test(NAME ${CMAKE_PROJECT_NAME} COMMAND ${CMAKE_PROJECT_NAME})

set(GCOVR_PATH "/usr/bin/gcovr")

setup_target_for_coverage_gcovr_html(
	NAME ${CMAKE_PROJECT_NAME}Coverage
	BASE_DIRECTORY "${CMAKE_SOURCE_DIR}/../../RoadChecker/" 
	EXECUTABLE ${CMAKE_PROJECT_NAME}
	DEPENDENCIES ${CMAKE_PROJECT_NAME}
)

#setup_target_for_coverage_lcov(
#	NAME ${CMAKE_PROJECT_NAME}Coverage
#	BASE_DIRECTORY "${CMAKE_SOURCE_DIR}/../../RoadChecker/" 
#	EXECUTABLE ${CMAKE_PROJECT_NAME}
#	DEPENDENCIES ${CMAKE_PROJECT_NAME}
#)
