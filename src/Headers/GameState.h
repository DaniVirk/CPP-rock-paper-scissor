#ifndef GAMESTATE_H
#define GAMESTATE_H



class GameState {
    bool started = false;
    int playerScore = 0;
    int computerScore = 0;

    public:
    bool GetStarted();
    void SetStarted(bool started);

    int GetPlayerScore();
    void SetPlayerScore(int score);
    void AddPlayerScore();

    int GetComputerScore();
    void SetComputerScore(int score);
    void AddComputerScore();
};



#endif //GAMESTATE_H
