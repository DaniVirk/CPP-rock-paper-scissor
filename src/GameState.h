#ifndef GAMESTATE_H
#define GAMESTATE_H



class GameState {
    bool started = false;

    public:
    bool GetStarted();
    void SetStarted(bool started);
};



#endif //GAMESTATE_H
