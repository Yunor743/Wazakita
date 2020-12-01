
cmake_minimum_required(VERSION 3.11)
project(Wazakita)
set (CMAKE_CXX_STANDARD 17)

add_executable(wazakita ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(wazakita PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(wazakita PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/task.cpp
)

