project(commands)

# make library
add_library(commands_base STATIC BaseCommand.cpp)

# make utils visible in cpp
include_directories("${Monitor_root}/utils")

# make utils visible in cmake structure and compile it
add_subdirectory("${Monitor_root}/utils" build)
target_link_libraries(commands_base utils)
