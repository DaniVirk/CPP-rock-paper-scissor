#ifndef CPP_ROCK_PAPER_SCISSOR_SRC_GAMEENGINE_H_
#define CPP_ROCK_PAPER_SCISSOR_SRC_GAMEENGINE_H_
#include <random>
#include <string>
#include "../Enum/game_enum.cpp"
#include "../Enum/game_decision.cpp"


class game_engine {
    static std::mt19937 gen;
    game_enum get_input();
    game_enum get_rps_value_from_rng(int value);
    game_decision get_game_decision(game_enum user, game_enum opponent);
    bool should_game_continue();
    std::string to_string(game_enum choice);

public:
    void start();
    static int random_number_generator();
};

#endif //CPP_ROCK_PAPER_SCISSOR_SRC_GAMEENGINE_H_
