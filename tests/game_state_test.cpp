#include <gtest/gtest.h>
#include "../src/Headers/game_state.h"

class GameStateTest : public ::testing::Test {
protected:
    game_state state;
};

TEST_F(GameStateTest, InitialState) {
    EXPECT_FALSE(state.get_started());
    EXPECT_EQ(state.get_player_score(), 0);
    EXPECT_EQ(state.get_computer_score(), 0);
}

TEST_F(GameStateTest, SetStarted) {
    state.set_started(true);
    EXPECT_TRUE(state.get_started());

    state.set_started(false);
    EXPECT_FALSE(state.get_started());
}

TEST_F(GameStateTest, PlayerScore) {
    state.set_player_score(5);
    EXPECT_EQ(state.get_player_score(), 5);

    state.add_player_score();
    EXPECT_EQ(state.get_player_score(), 6);
}

TEST_F(GameStateTest, ComputerScore) {
    state.set_computer_score(3);
    EXPECT_EQ(state.get_computer_score(), 3);

    state.add_computer_score();
    EXPECT_EQ(state.get_computer_score(), 4);
}