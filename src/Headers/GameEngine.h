#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <random>
#include <string>
#include "../Enum/GameEnum.cpp"
#include "../Enum/GameDecision.cpp"


class GameEngine {
    static std::mt19937 gen;
    GameEnum GetInput();
    GameEnum GetRPSValueFromRng(int value);
    GameDecision GetGameDecision(GameEnum user, GameEnum opponent);
    bool ShouldGameContinue();
    std::string ToString(GameEnum choice);

public:
    void Start();

    static int RandomNumberGenerator();
};



#endif //GAMEENGINE_H
