#include "../pch.h"
#include "Day1/CalorieCounting.h"
#include "../TestUtils.h"

using namespace std;
using namespace TestUtils;

string FILE_PATH(TEST_DIRECTORY + "Day1/Files/");
TEST(CalorieCountingTest, MaxCaloriesSmallInput) {

  CalorieCounting calorieCounting;
  auto caloriePacks = calorieCounting.ReadFile(FILE_PATH + "small_input.txt");

  EXPECT_GT(caloriePacks.size(), 0);
  EXPECT_EQ(calorieCounting.GetMaxCalories(caloriePacks), 24000);
}

TEST(CalorieCountingTest, MaxCaloriesInput) {
  CalorieCounting calorieCounting;
  auto caloriePacks = calorieCounting.ReadFile(FILE_PATH + "part1.txt");

  EXPECT_GT(caloriePacks.size(), 0);
  EXPECT_EQ(calorieCounting.GetMaxCalories(caloriePacks), 66719);
}