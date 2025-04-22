#include "GameState.h"

bool GameState::GetStarted() {
    return started;
}

void GameState::SetStarted(const bool started) {
    this->started = started;
}

int GameState::GetPlayerScore() {
    return playerScore;
}

void GameState::SetPlayerScore(const int score) {
    this->playerScore = score;
}

void GameState::AddPlayerScore() {
    this->playerScore++;
}

int GameState::GetComputerScore() {
    return computerScore;
}

void GameState::SetComputerScore(const int score) {
    this->computerScore = score;
}

void GameState::AddComputerScore() {
    this->computerScore++;
}