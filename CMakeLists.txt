cmake_minimum_required(VERSION 3.16.3)

project(UniquePointer-Tutorial)

set (CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${PROJECT_SOURCE_DIR}/Unique_ptr)

add_subdirectory(Unique_ptr)

add_executable(main main.cpp)

target_link_libraries(main Unique_ptr)


