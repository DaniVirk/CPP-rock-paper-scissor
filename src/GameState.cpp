#include "GameState.h"
bool started;

bool GameState::GetStarted() {
    return started;
}

void GameState::SetStarted(const bool started) {
    this->started = started;
}

