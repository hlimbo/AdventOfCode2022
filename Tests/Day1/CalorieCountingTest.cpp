#include "../pch.h"
#include "Day1/CalorieCounting.h"
#include "../TestUtils.h"

using namespace std;
using namespace TestUtils;

const string FILE_PATH(TEST_DIRECTORY + "Day1/Files/");
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

TEST(CalorieCountingTest, Top3CaloriesSmallInput) {
  CalorieCounting calorieCounting;
  auto caloriePacks = calorieCounting.ReadFile(FILE_PATH + "small_input.txt");
  vector<int> top3Calories = calorieCounting.GetTop3Calories(caloriePacks);

  int expected[] = {24000, 11000, 10000};
  int arrayLength = sizeof(expected) / sizeof(int);

  EXPECT_EQ(top3Calories.size(), arrayLength);
  for (int i = 0; i < arrayLength; ++i) {
    EXPECT_EQ(top3Calories[i], expected[i]);
  }
}

TEST(CalorieCountingTest, Top3CaloriesInput) {
  CalorieCounting calorieCounting;
  auto caloriePacks = calorieCounting.ReadFile(FILE_PATH + "part1.txt");
  vector<int> top3Calories = calorieCounting.GetTop3Calories(caloriePacks);

  // total: 198,551
  int expected[] = { 66719, 66339, 65493 };
  int arrayLength = sizeof(expected) / sizeof(int);

  EXPECT_EQ(top3Calories.size(), arrayLength);
  for (int i = 0; i < arrayLength; ++i) {
    EXPECT_EQ(top3Calories[i], expected[i]);
  }
}