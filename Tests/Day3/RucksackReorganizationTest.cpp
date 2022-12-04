#include "gtest/gtest.h"
#include "../TestUtils.h"
#include "Day3/RucksackReorganization.h"

using namespace std;
using namespace TestUtils;
using namespace RucksackReorganization;

const string FILE_PATH(TEST_DIRECTORY + "Day3/Files/");

TEST(RucksackReorganizationTest, SmallInputPart1) {
  vector<string> rucksacks = ReadFile(FILE_PATH + "small_input.txt");
  int errorSum = CalculateErrorSum(rucksacks);
  
  EXPECT_EQ(errorSum, 157);
}

TEST(RucksackReorganizationTest, Part1) {
  vector<string> rucksacks = ReadFile(FILE_PATH + "part1.txt");
  int errorSum = CalculateErrorSum(rucksacks);
  EXPECT_EQ(errorSum, 8298);
}

TEST(RucksackReorganizationTest, SmallInputPart2) {
  vector<string> rucksacks = ReadFile(FILE_PATH + "small_input.txt");
  int badgesSum = CalculateBadgesSum(rucksacks);
  EXPECT_EQ(badgesSum, 70);
}

TEST(RucksackReorganizationTest, Part2) {
  vector<string> rucksacks = ReadFile(FILE_PATH + "part1.txt");
  int badgesSum = CalculateBadgesSum(rucksacks);
  EXPECT_EQ(badgesSum, 2708);
}