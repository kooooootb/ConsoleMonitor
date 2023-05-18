cmake_minimum_required(VERSION 3.22)
project(Monitor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

cmake_policy(VERSION 3.22...3.24)

add_subdirectory(src)

# for devs
if(CMAKE_CURRENT_LIST_DIR STREQUAL CMAKE_SOURCE_DIR)
    # build tests
    add_subdirectory(tests)
endif()
