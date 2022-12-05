#include "gtest/gtest.h"
#include "../TestUtils.h"
#include "Day4/CampCleanup.h"

using namespace std;
using namespace TestUtils;
using namespace CampCleanup;

const string FILE_PATH(TEST_DIRECTORY + "Day4/Files/");

TEST(CampCleanupTest, SmallInputPart1) {
  auto ranges = ReadFile(FILE_PATH + "small_input.txt");
  int fullOverlapCount = GetFullOverlapCleanAssignmentPairs(ranges);
  EXPECT_EQ(fullOverlapCount, 2);
}

TEST(CampCleanupTest, Part1) {
  auto ranges = ReadFile(FILE_PATH + "part1.txt");
  int fullOverlapCount = GetFullOverlapCleanAssignmentPairs(ranges);
  EXPECT_EQ(fullOverlapCount, 605);
}

TEST(CampCleanupTest, SmallInputPart2) {
  auto ranges = ReadFile(FILE_PATH + "small_input.txt");
  int overlapCount = GetOverlapCleanAssignmentPairs(ranges);
  EXPECT_EQ(overlapCount, 4);
}

TEST(CampCleanupTest, Part2) {
  auto ranges = ReadFile(FILE_PATH + "part1.txt");
  int overlapCount = GetOverlapCleanAssignmentPairs(ranges);
  EXPECT_EQ(overlapCount, 914);
}