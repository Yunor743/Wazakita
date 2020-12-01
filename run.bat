@ECHO OFF
if not exist ".\cmake-build-debug\" mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
cmake --build .