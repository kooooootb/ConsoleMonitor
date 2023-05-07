cmake_minimum_required(VERSION 3.22)
project(Monitor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

set(Project_root ${CMAKE_CURRENT_LIST_DIR})

include_directories(monitor)

add_executable(main main.cpp)

add_subdirectory(tests)
add_subdirectory(monitor)

target_include_directories(main PUBLIC monitor)
target_link_libraries(main monitor mycommands)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

