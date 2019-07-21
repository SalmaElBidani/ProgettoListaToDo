cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(TEST_SOURCE_FILES runAllTests.cpp ListToDoTest.cpp)

add_subdirectory(./Lib/googletest)
set(gtest_SOURCE_DIR, ./Lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Test ${TEST_SOURCE_FILES})
target_link_libraries(Test gtest gtest_main core)










