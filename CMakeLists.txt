cmake_minimum_required(VERSION 3.31)
project(CPP_rock_paper_scissor)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP_rock_paper_scissor main.cpp
        src/Game_engine.cpp
        src/Headers/Game_engine.h
        src/Enum/game_enum.cpp
        src/Enum/game_decision.cpp
        src/Game_state.cpp
        src/Headers/Game_state.h)
