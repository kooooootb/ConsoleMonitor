project(logic)

SET(commands_list Init.cpp Full.cpp Empty.cpp Enter.cpp Copy.cpp Move.cpp Del.cpp Squeeze.cpp Help.cpp)
add_library(logic STATIC ${commands_list})

target_include_directories(logic PUBLIC ..)
target_link_libraries(logic PUBLIC commands)

target_include_directories(logic PUBLIC "${Monitor_root}/utils")
target_link_libraries(logic PUBLIC utils)
