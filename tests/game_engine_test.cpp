#include <gtest/gtest.h>
#include "../src/Headers/game_engine.h"

#include <stdexcept>

class GameEngineTest : public ::testing::Test {
protected:
    game_engine engine;
};

TEST_F(GameEngineTest, GetRpsValueFromRng) {
    // Test ROCK range
    EXPECT_EQ(engine.get_rps_value_from_rng(500), game_enum::ROCK);
    EXPECT_EQ(engine.get_rps_value_from_rng(1000), game_enum::ROCK);

    // Test PAPER range
    EXPECT_EQ(engine.get_rps_value_from_rng(1001), game_enum::PAPER);
    EXPECT_EQ(engine.get_rps_value_from_rng(1999), game_enum::PAPER);

    // Test SCISSOR range
    EXPECT_EQ(engine.get_rps_value_from_rng(2000), game_enum::SCISSOR);
    EXPECT_EQ(engine.get_rps_value_from_rng(3000), game_enum::SCISSOR);

    // Test out of range
    EXPECT_THROW(engine.get_rps_value_from_rng(3001), std::out_of_range);
}

TEST_F(GameEngineTest, GetGameDecision) {
    // Test ROCK scenarios
    EXPECT_EQ(engine.get_game_decision(game_enum::ROCK, game_enum::ROCK), game_decision::DRAW);
    EXPECT_EQ(engine.get_game_decision(game_enum::ROCK, game_enum::PAPER), game_decision::LOSE);
    EXPECT_EQ(engine.get_game_decision(game_enum::ROCK, game_enum::SCISSOR), game_decision::WIN);

    // Test PAPER scenarios
    EXPECT_EQ(engine.get_game_decision(game_enum::PAPER, game_enum::PAPER), game_decision::DRAW);
    EXPECT_EQ(engine.get_game_decision(game_enum::PAPER, game_enum::SCISSOR), game_decision::LOSE);
    EXPECT_EQ(engine.get_game_decision(game_enum::PAPER, game_enum::ROCK), game_decision::WIN);

    // Test SCISSOR scenarios
    EXPECT_EQ(engine.get_game_decision(game_enum::SCISSOR, game_enum::SCISSOR), game_decision::DRAW);
    EXPECT_EQ(engine.get_game_decision(game_enum::SCISSOR, game_enum::ROCK), game_decision::LOSE);
    EXPECT_EQ(engine.get_game_decision(game_enum::SCISSOR, game_enum::PAPER), game_decision::WIN);
}

TEST_F(GameEngineTest, ToString) {
    EXPECT_EQ(engine.to_string(game_enum::ROCK), "Rock");
    EXPECT_EQ(engine.to_string(game_enum::PAPER), "Paper");
    EXPECT_EQ(engine.to_string(game_enum::SCISSOR), "Scissor");
}

TEST_F(GameEngineTest, RandomNumberGenerator) {
    // Test that random numbers are within expected range
    for (int i = 0; i < 1000; ++i) {
        int number = engine.random_number_generator();
        EXPECT_GE(number, 1);
        EXPECT_LE(number, 3000);
    }
}