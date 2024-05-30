This is the toy Unit Test project to demonstrate basic operations on a toy class called RoadChecker to TTTech-Auto members.
for further information please refer to:
https://google.github.io/googletest/

TO Build under unit/RoadChecker/ folder: 
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug


To run:
./build/RoadCheckerTest
or
ctest --test-dir build

for coverage:
lcov -c -d /path/to/gcda_files -o coverage.info
genhtml -o coverage_out_html coverage.info --ignore-errors source
