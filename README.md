This is the toy Unit Test project to demonstrate basic operations on a toy class called RoadChecker to TTTech-Auto members.
for further information please refer to:
https://google.github.io/googletest/

RoadChecker Unit:
checkState
- RoadChecker reads vehicle speed from Speed Unit
- If vehicle is moving in forward direction above the speed limit, RoadChecker reads processed road condition from AccelerometerUnit.
- If the processed road condition value is above broken road limit, 
    1st RoadChecker sets road state member as broken and 
    2nd RoadChecker tries to reads gps location from GPS unit.
- If RoadChecker reads GPS location succesfully then reports road state to State handler unit. Upon first report fail case RoadChecker tries to report twice.

getState
- Latest Road state can be read from RoadChecker.

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
