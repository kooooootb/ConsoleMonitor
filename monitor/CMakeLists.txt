project(monitor)

# set monitor project root directory
set(Monitor_root ${CMAKE_CURRENT_LIST_DIR})

# make monitor library
add_library(monitor STATIC Monitor.cpp)

# make commands files visible in cpp files
target_include_directories(monitor PUBLIC "${Monitor_root}/commands")

# make commands directory visible in cmake
add_subdirectory("${Monitor_root}/commands") # includes adding util funcs
target_link_libraries(monitor PRIVATE commands)

# make commands files visible in cpp files
target_include_directories(monitor PUBLIC "${Monitor_root}/utils")

# make commands directory visible in cmake
target_link_libraries(monitor PRIVATE utils)
