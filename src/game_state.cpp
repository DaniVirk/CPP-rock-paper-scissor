#include "Headers/game_state.h"

bool game_state::get_started() {
    return _started;
}

void game_state::set_started(const bool started) {
    this->_started = started;
}

int game_state::get_player_score() {
    return _player_score;
}

void game_state::set_player_score(int score) {
    _player_score = score;
}

void game_state::add_player_score() {
    _player_score++;
}

int game_state::get_computer_score() {
    return _computer_score;
}

void game_state::set_computer_score(const int score) {
    _computer_score = score;
}

void game_state::add_computer_score() {
    _computer_score++;
}