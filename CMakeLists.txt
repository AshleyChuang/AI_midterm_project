cmake_minimum_required(VERSION 3.6)
project(AI_midterm_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Game.cpp
    Game.hpp
    main.cpp
    MCTS.cpp
    MCTS.hpp
    Node.cpp
    Node.hpp)

add_executable(AI_midterm_project ${SOURCE_FILES})