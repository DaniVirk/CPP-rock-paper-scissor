#ifndef CPP_ROCK_PAPER_SCISSOR_SRC_GAMESTATE_H_
#define CPP_ROCK_PAPER_SCISSOR_SRC_GAMESTATE_H_



class game_state {
    bool _started = false;
    int _player_score = 0;
    int _computer_score = 0;

    public:
    bool get_started();
    void set_started(bool started);

    int get_player_score();
    void set_player_score(int score);
    void add_player_score();

    int get_computer_score();
    void set_computer_score(int score);
    void add_computer_score();
};



#endif //CPP_ROCK_PAPER_SCISSOR_SRC_GAMESTATE_H_
