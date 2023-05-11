project(mycommands)

# make library
SET(commands_list Init.cpp Help.cpp)
add_library(mycommands STATIC ${commands_list})

# make utils visible in cpp
include_directories("${Monitor_root}/commands")

# make utils visible in cmake structure and compile it
add_subdirectory("${Monitor_root}/commands" build)
target_link_libraries(mycommands commands_base)
