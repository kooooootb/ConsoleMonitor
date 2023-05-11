project(Monitor)

# make monitor library
add_library(monitor STATIC MonitorOutput.cpp MonitorInput.cpp)
target_include_directories(monitor PUBLIC "${CMAKE_CURRENT_LIST_DIR}/includes")

# link with our base commands
target_link_libraries(monitor PUBLIC commands_base)

# and utilities
target_link_libraries(monitor PUBLIC utils)
