#include "Headers/GameEngine.h"
#include <iostream>
#include <random>
#include "Headers/GameState.h"
#include <limits>
#include <windows.h>

using std::cout;
using std::endl;
using std::cin;

void GameEngine::Start() {
    cout << "Welcome to rock paper scissor - Made by Danial" << endl;
    const HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 15);
    GameState gameState;
    gameState.SetStarted(true);

    while (gameState.GetStarted()) {
        cout << "Chose one of the following: 0. ROCK - 1. PAPER - 2. SCISSOR" << endl;
        const GameEnum userChoice = GetInput();
        const auto rngNumber = RandomNumberGenerator();
        const GameEnum gameChoice = GetRPSValueFromRng(rngNumber);
        const auto decision = GetGameDecision(userChoice, gameChoice);

        if (decision == GameDecision::LOSE) {
            gameState.AddComputerScore();
            SetConsoleTextAttribute(consoleHandle, 4);
            cout << "You lost | Your score: " << gameState.GetPlayerScore() << endl;
            cout << "Computer's score: " << gameState.GetComputerScore() << endl;
        }

        if (decision == GameDecision::WIN) {
            gameState.AddPlayerScore();
            SetConsoleTextAttribute(consoleHandle, 10);
            cout << "You win | Your score: " << gameState.GetPlayerScore() << endl;
            cout << "Computer's score: " << gameState.GetComputerScore() << endl;
        }

        if (decision == GameDecision::DRAW) {
            SetConsoleTextAttribute(consoleHandle, 1);
            cout << "You draw" << endl;
        }

        SetConsoleTextAttribute(consoleHandle, 15);
        gameState.SetStarted(ShouldGameContinue());
    }

    cout << "You scored: " << gameState.GetPlayerScore() << endl;
    cout << "Computer scored: " << gameState.GetComputerScore() << endl;
    cout << "Goodbye!!" << endl;
}

GameEnum GameEngine::GetInput() {
    int inputInt;

    while (true) {
        cin >> inputInt;
        if (cin.fail()) {
            cout << "Incorrect input\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (inputInt == static_cast<int>(GameEnum::ROCK)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return GameEnum::ROCK;
        }
        if (inputInt == static_cast<int>(GameEnum::PAPER)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return GameEnum::PAPER;
        }
        if (inputInt == static_cast<int>(GameEnum::SCISSOR)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return GameEnum::SCISSOR;
        }

        cout << "Incorrect input - Please try again: ";
        cin.clear();
        cin.ignore();
    }
}

int GameEngine::RandomNumberGenerator() {
    std::random_device rd;
    std::uniform_int_distribution distrib(1, 3000);
    return distrib(gen);
}

//Init once
std::mt19937 GameEngine::gen(std::random_device{}());

GameEnum GameEngine::GetRPSValueFromRng(const int value) {
    if (value <= 1000) {
        return GameEnum::ROCK;
    }
    if (value < 2000) {
        return GameEnum::PAPER;
    }
    if (value <= 3000) {
        return GameEnum::SCISSOR;
    }
    throw std::out_of_range("Random value out of expected range");
}

GameDecision GameEngine::GetGameDecision(const GameEnum user, const GameEnum opponent) {
    cout << "You chose: " << ToString(user) << endl;
    cout << "Computer chose: " << ToString(opponent) << endl;

    //ROCK
    if (user == GameEnum::ROCK) {
        if (opponent == GameEnum::PAPER) {
            return GameDecision::LOSE;
        }

        if (opponent == GameEnum::SCISSOR) {
            return GameDecision::WIN;
        }

        return GameDecision::DRAW;
    }

    //PAPER
    if (user == GameEnum::PAPER) {
        if (opponent == GameEnum::SCISSOR) {
            return GameDecision::LOSE;
        }

        if (opponent == GameEnum::ROCK) {
            return GameDecision::WIN;
        }
        return GameDecision::DRAW;
    }

    //SCISSOR
    if (user == GameEnum::SCISSOR) {
        if (opponent == GameEnum::ROCK) {
            return GameDecision::LOSE;
        }
        if (opponent == GameEnum::PAPER) {
            return GameDecision::WIN;
        }
        return GameDecision::DRAW;
    }

    return GameDecision::LOSE;
}

bool GameEngine::ShouldGameContinue() {
    std::string input;
    while (true) {
        std::cout << "Do you want to continue? [y/n] ";
        std::getline(std::cin, input);

        // normalize to lowercase if you want to support variants
        if (input == "y" || input == "yes" || input == "Y" || input == "YES") {
            return true;
        }

        if (input == "n" || input == "no" || input == "N" || input == "NO") {
            return false;
        }

        std::cout << "Invalid input. Please enter 'y' or 'n'.\n\n";
    }
}

std::string GameEngine::ToString(GameEnum choice) {
    switch (choice) {
        case GameEnum::ROCK: return "Rock";
        case GameEnum::PAPER: return "Paper";
        case GameEnum::SCISSOR: return "Scissor";
        default: return "Unknown";
    }
}