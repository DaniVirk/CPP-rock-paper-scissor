﻿#include "Headers/game_engine.h"
#include <iostream>
#include <random>
#include "Headers/game_state.h"
#include <limits>
#include <windows.h>

using std::cout;
using std::endl;
using std::cin;

void game_engine::start() {
    cout << "Welcome to rock paper scissor - Made by Danial" << endl;
    const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, 15);
    game_state game_state;
    game_state.set_started(true);

    while (game_state.get_started()) {
        cout << "Chose one of the following: 0. ROCK - 1. PAPER - 2. SCISSOR" << endl;
        const game_enum user_choice = get_input();
        const auto rng_number = random_number_generator();
        const game_enum game_choice = get_rps_value_from_rng(rng_number);
        const auto decision = get_game_decision(user_choice, game_choice);

        if (decision == game_decision::LOSE) {
            game_state.add_computer_score();
            SetConsoleTextAttribute(console_handle, 4);
            cout << "You lost | Your score: " << game_state.get_player_score() << endl;
            cout << "Computer's score: " << game_state.get_computer_score() << endl;
        }

        if (decision == game_decision::WIN) {
            game_state.add_player_score();
            SetConsoleTextAttribute(console_handle, 10);
            cout << "You win | Your score: " << game_state.get_player_score() << endl;
            cout << "Computer's score: " << game_state.get_computer_score() << endl;
        }

        if (decision == game_decision::DRAW) {
            SetConsoleTextAttribute(console_handle, 1);
            cout << "You draw" << endl;
        }

        SetConsoleTextAttribute(console_handle, 15);
        game_state.set_started(should_game_continue());
    }

    cout << "You scored: " << game_state.get_player_score() << endl;
    cout << "Computer scored: " << game_state.get_computer_score() << endl;
    cout << "Goodbye!!" << endl;
}

game_enum game_engine::get_input() {
    int input_int;
    while (true) {
        cin >> input_int;
        if (cin.fail()) {
            cout << "Incorrect input\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (input_int == static_cast<int>(game_enum::ROCK)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return game_enum::ROCK;
        }
        if (input_int == static_cast<int>(game_enum::PAPER)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return game_enum::PAPER;
        }
        if (input_int == static_cast<int>(game_enum::SCISSOR)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return game_enum::SCISSOR;
        }

        cout << "Incorrect input - Please try again: ";
        cin.clear();
        cin.ignore();
    }
}

int game_engine::random_number_generator() {
    std::random_device rd;
    std::uniform_int_distribution distrib(1, 3000);
    return distrib(gen);
}

//Init once
std::mt19937 game_engine::gen(std::random_device{}());

game_enum game_engine::get_rps_value_from_rng(const int value) {
    if (value <= 1000) {
        return game_enum::ROCK;
    }
    if (value < 2000) {
        return game_enum::PAPER;
    }
    if (value <= 3000) {
        return game_enum::SCISSOR;
    }
    throw std::out_of_range("Random value out of expected range");
}

game_decision game_engine::get_game_decision(const game_enum user, const game_enum opponent) {
    cout << "You chose: " << to_string(user) << endl;
    cout << "Computer chose: " << to_string(opponent) << endl;

    //ROCK
    if (user == game_enum::ROCK) {
        if (opponent == game_enum::PAPER) {
            return game_decision::LOSE;
        }

        if (opponent == game_enum::SCISSOR) {
            return game_decision::WIN;
        }

        return game_decision::DRAW;
    }

    //PAPER
    if (user == game_enum::PAPER) {
        if (opponent == game_enum::SCISSOR) {
            return game_decision::LOSE;
        }

        if (opponent == game_enum::ROCK) {
            return game_decision::WIN;
        }
        return game_decision::DRAW;
    }

    //SCISSOR
    if (user == game_enum::SCISSOR) {
        if (opponent == game_enum::ROCK) {
            return game_decision::LOSE;
        }
        if (opponent == game_enum::PAPER) {
            return game_decision::WIN;
        }
        return game_decision::DRAW;
    }

    return game_decision::LOSE;
}

bool game_engine::should_game_continue() {
    std::string input;
    while (true) {
        cout << "Do you want to continue? [y/n] ";
        std::getline(std::cin, input);

        // normalize to lowercase if you want to support variants
        if (input == "y" || input == "yes" || input == "Y" || input == "YES") {
            return true;
        }

        if (input == "n" || input == "no" || input == "N" || input == "NO") {
            return false;
        }

        cout << "Invalid input. Please enter 'y' or 'n'.\n\n";
    }
}

std::string game_engine::to_string(const game_enum choice) {
    switch (choice) {
        case game_enum::ROCK: return "Rock";
        case game_enum::PAPER: return "Paper";
        case game_enum::SCISSOR: return "Scissor";
        default: return "Unknown";
    }
}