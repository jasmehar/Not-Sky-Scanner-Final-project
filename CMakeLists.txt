cmake_minimum_required(VERSION 3.10) #Same version as mp

#Setting c++ standard the same as mp
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Adding Catch2
find_package(Catch2 REQUIRED)

#PROJECT
project(NotSkyScanner)

# Run CMakeLists in src_dir to build the student's code.
add_subdirectory(./code/src)

#executable for main
add_executable(main code/entry/main.cpp)
target_link_libraries(main PRIVATE src)

#Collects all the source files in tests into variable tests_src
#configure_depends updates make whenever files are modified
file(GLOB_RECURSE tests_src CONFIGURE_DEPENDS tests/*.cpp)

#executable for test
include(Catch)

add_executable(test ${tests_src})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain src)

catch_discover_tests(test)