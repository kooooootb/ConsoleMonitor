project(commands)

# make library
SET(commands_list Init.cpp Full.cpp Empty.cpp Enter.cpp)
add_library(commands STATIC CommandHelp.cpp CommandFactory.cpp BaseCommand.cpp ${commands_list})

# make utils visible in cpp
include_directories("${Monitor_root}/utils")

# make utils visible in cmake structure and compile it
add_subdirectory("${Monitor_root}/utils" build)
target_link_libraries(commands utils)
