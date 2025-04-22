#ifndef SRC_GAMEENGINE_H
#define SRC_GAMEENGINE_H
#include <random>
#include <string>
#include "../Enum/game_enum.cpp"
#include "../Enum/game_decision.cpp"


class game_engine {
    static std::mt19937 gen;
    game_enum GetInput();
    game_enum GetRPSValueFromRng(int value);
    game_decision GetGameDecision(game_enum user, game_enum opponent);
    bool ShouldGameContinue();
    std::string ToString(game_enum choice);

public:
    void Start();

    static int RandomNumberGenerator();
};



#endif //SRC_GAMEENGINE_H
