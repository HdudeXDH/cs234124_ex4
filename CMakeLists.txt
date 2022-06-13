cmake_minimum_required(VERSION 3.21)
project(cs234124_ex4)

set(CMAKE_CXX_STANDARD 14)
file(GLOB playsSRC
        "Players/*.cpp"
        "Cards/*.cpp")

add_executable(cs234124_ex4 main.cpp ${playsSRC} Exception.h Mtmchkin.cpp utilities.cpp)
#add_executable(cs234124_ex4 main.cpp)