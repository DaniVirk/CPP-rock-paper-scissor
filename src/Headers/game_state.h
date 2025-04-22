#ifndef SRC_GAMESTATE_H
#define SRC_GAMESTATE_H



class game_state {
    bool _started = false;
    int _player_score = 0;
    int _computer_score = 0;

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



#endif //SRC_GAMESTATE_H
