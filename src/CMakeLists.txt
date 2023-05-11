project(Monitor)

# make monitor library
add_library(monitor STATIC MonitorOutput.cpp MonitorInput.cpp)

# link with our commands
target_link_libraries(monitor PUBLIC commands_base)

# and utilities
target_link_libraries(monitor PUBLIC utils)
