This is the toy Unit Test project to demonstrate basic operations on a toy class called RoadChecker to TTTech-Auto members.
for further information please refer to:
https://google.github.io/googletest/

To build (under unit/RoadChecker/ folder): 
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug


To run test:
./build/RoadCheckerTest
or
ctest --test-dir build


To get coverage info in html:
lcov -c -d /path/to/gcda_files -o coverage.info
genhtml -o coverage_out_html coverage.info --ignore-errors source

or 

cmake --build build --config Debug --target RoadCheckerTestCoverage
if gcovr is installed via: sudo apt install gcovr
