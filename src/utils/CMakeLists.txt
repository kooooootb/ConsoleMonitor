project(Monitor_utils)

add_library(monitor_utils STATIC Parser.cpp utilFunctions.cpp)
target_include_directories(monitor_utils)
