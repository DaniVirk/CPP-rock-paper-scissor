cmake_minimum_required(VERSION 3.31)
project(CPP_rock_paper_scissor)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP_rock_paper_scissor main.cpp
        src/GameEngine.cpp
        src/Headers/GameEngine.h
        src/Enum/GameEnum.cpp
        src/Enum/GameDecision.cpp
        src/GameState.cpp
        src/Headers/GameState.h)
