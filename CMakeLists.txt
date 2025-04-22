cmake_minimum_required(VERSION 3.14)
project(CPP_rock_paper_scissor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Create a library target for your game code
add_library(game_lib
        src/game_engine.cpp
        src/game_state.cpp
        src/Headers/game_engine.h
        src/Headers/game_state.h
        src/Enum/game_enum.cpp
        src/Enum/game_decision.cpp
)

# Create your main executable
add_executable(CPP_rock_paper_scissor main.cpp)
target_link_libraries(CPP_rock_paper_scissor game_lib)

# Create test executable
add_executable(
        game_tests
        tests/game_state_test.cpp
)

target_link_libraries(
        game_tests
        GTest::gtest_main
        game_lib
)

include(GoogleTest)
gtest_discover_tests(game_tests)