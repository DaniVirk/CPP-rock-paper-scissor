#include "GameEngine.h"
#include <iostream>
#include "GameEnum.cpp"

using std::cout;
using std::endl;
using std::cin;

void GameEngine::Start() {
    cout << "Welcome to rock paper scissor - Made by Danial" << endl;

    cout << "Chose one of the following: 0. ROCK - 1. PAPER - 2. SCISSOR" << endl;

    std::string input = GetInput();


}

std::string GameEngine::GetInput() {

    int inputInt;

    while (true) {
        cin >> inputInt;
        if (cin.fail()) {
            cout << "Incorrect input\n";
            cin.clear();
            cin.ignore();
        }

        if (inputInt == ROCK) {
            return "rock";
        }
        if (inputInt == PAPER) {
            return "paper";
        }
        if (inputInt == SCISSOR) {
            return "scissor";
        }

        cout << "Incorrect input - Please try again: ";
        cin.clear();
        cin.ignore();
    }



    return "";
}