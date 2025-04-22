#include "Headers/game_state.h"

bool game_state::GetStarted() {
    return _started;
}

void game_state::SetStarted(const bool started) {
    this->_started = started;
}

int game_state::GetPlayerScore() {
    return _player_score;
}

void game_state::SetPlayerScore(const int score) {
    this->_player_score = score;
}

void game_state::AddPlayerScore() {
    this->_player_score++;
}

int game_state::GetComputerScore() {
    return _computer_score;
}

void game_state::SetComputerScore(const int score) {
    this->_computer_score = score;
}

void game_state::AddComputerScore() {
    this->_computer_score++;
}