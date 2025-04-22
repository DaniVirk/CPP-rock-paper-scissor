#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <string>

#include "../Enum/GameEnum.cpp"
#include "../Enum/GameDecision.cpp"


class GameEngine {
    GameEnum GetInput();
    GameEnum GetRPSValueFromRng(int value);
    GameDecision GetGameDecision(GameEnum user, GameEnum opponent);
    bool ShouldGameContinue();
    std::string ToString(GameEnum choice);

public:
    void Start();
    int RandomNumberGenerator();
};



#endif //GAMEENGINE_H
