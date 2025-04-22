cmake_minimum_required(VERSION 3.31)
project(CPP_rock_paper_scissor)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP_rock_paper_scissor main.cpp
        src/GameEngine.cpp
        src/GameEngine.h
        src/GameEnum.cpp
        src/GameDecision.cpp
        src/GameState.cpp
        src/GameState.h)
