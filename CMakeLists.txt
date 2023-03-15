cmake_minimum_required(VERSION 3.24)
project(Project_Chaos)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Project_Chaos main.cpp include/defs.h include/draw.cpp include/draw.h include/init.cpp include/init.h include/input.cpp include/input.h include/structs.h include/stage.cpp include/stage.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2test SDL2_image SDL2_mixer -lsdl2_mixer)
