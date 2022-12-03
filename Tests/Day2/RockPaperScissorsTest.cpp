#include "gtest/gtest.h"
#include "../TestUtils.h"
#include "Day2/RockPaperScissors.h"

using namespace std;
using namespace TestUtils;
using namespace RPS;

const string FILE_PATH(TEST_DIRECTORY + "Day2/Files/");

TEST(RockPaperScissorsTest, SmallInput) {
  vector<vector<char>> rounds = ReadFile(FILE_PATH + "small_input.txt");
  int score = calculateStrategyScore(rounds);
  EXPECT_EQ(score, 15);
}

TEST(RockPaperScissorsTest, Part1) {
  vector<vector<char>> rounds = ReadFile(FILE_PATH + "part1.txt");
  int score = calculateStrategyScore(rounds);
  EXPECT_EQ(score, 10404);
}

TEST(RockPaperScissorsTest, SmallInput2) {
  vector<vector<char>> rounds = ReadFile(FILE_PATH + "small_input.txt");
  int score = calculateStrategyScore2(rounds);
  EXPECT_EQ(score, 12);
}

TEST(RockPaperScissorsTest, Part2) {
  vector<vector<char>> rounds = ReadFile(FILE_PATH + "part1.txt");
  int score = calculateStrategyScore2(rounds);
  EXPECT_EQ(score, 10334);
}