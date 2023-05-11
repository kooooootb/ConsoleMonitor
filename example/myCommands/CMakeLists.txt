project(mycommands)

# make library
add_library(mycommands STATIC Init.cpp Help.cpp)
target_include_directories(mycommands PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# link it with commands bases
target_link_libraries(mycommands commands_base)
