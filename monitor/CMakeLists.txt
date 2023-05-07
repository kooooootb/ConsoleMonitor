#project(monitor)

# set monitor project root directory
set(Monitor_root ${CMAKE_CURRENT_LIST_DIR})

# make monitor library
add_library(monitor STATIC MonitorOutput.cpp MonitorInput.cpp)

# make commands files visible in cpp files
target_include_directories(monitor PUBLIC "${Monitor_root}/mycommands")

# make commands directory visible in cmake
add_subdirectory("${Monitor_root}/mycommands") # includes adding util funcs

# make commands_base files visible in cpp files
target_include_directories(monitor PUBLIC "${Monitor_root}/commands")

# make commands_base directory visible in cmake
target_link_libraries(monitor PRIVATE commands_base)

# make utils files visible in cpp files
target_include_directories(monitor PUBLIC "${Monitor_root}/utils")

# make utils directory visible in cmake
target_link_libraries(monitor PRIVATE utils)
