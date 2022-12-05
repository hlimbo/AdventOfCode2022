#include "gtest/gtest.h"
#include "../TestUtils.h"
#include "Day5/SupplyStacks.h"

using namespace std;
using namespace TestUtils;
using namespace SupplyStacks;

const string FILE_PATH(TEST_DIRECTORY + "Day5/Files/");

TEST(SupplyStacksTest, SmallInputPart1) {

  const string items("PMCDZN");
  vector<stack<char>> stacks = GenerateStacks(3);
  AddItems(stacks, 2, items, 0, 1);
  AddItems(stacks, 1, items, 1, 3);
  AddItems(stacks, 0, items, 4, 2);

  auto instructions = ReadFile(FILE_PATH + "small_input.txt");
  string topCrates(BeginCraneOperations1(stacks, instructions));

  EXPECT_STREQ(topCrates.c_str(), "CMZ");
}

TEST(SupplyStacksTest, Part1) {
  const string items("JWHGRSVPNRFWTVCWVLQZJGCGCWLFZCPGHQTBJCHRPMZNLTHMCDVWPWRF");
  vector<stack<char>> stacks = GenerateStacks(9);
  
  AddItems(stacks, 8, items, 0, 7);
  AddItems(stacks, 7, items, 7, 8);
  AddItems(stacks, 6, items, 15, 8);

  AddItems(stacks, 5, items, 23, 6);
  AddItems(stacks, 4, items, 29, 7);
  AddItems(stacks, 3, items, 36, 4);

  AddItems(stacks, 2, items, 40, 5);
  AddItems(stacks, 1, items, 45, 8);
  AddItems(stacks, 0, items, 53, 3);

  auto instructions = ReadFile(FILE_PATH + "part1.txt");
  string topCrates(BeginCraneOperations1(stacks, instructions));

  EXPECT_STREQ(topCrates.c_str(), "CVCWCRTVQ");
}

TEST(SupplyStacksTest, SmallInputPart2) {
  const string items("PMCDZN");
  vector<stack<char>> stacks = GenerateStacks(3);
  AddItems(stacks, 2, items, 0, 1);
  AddItems(stacks, 1, items, 1, 3);
  AddItems(stacks, 0, items, 4, 2);

  auto instructions = ReadFile(FILE_PATH + "small_input.txt");
  string topCrates(BeginCraneOperations2(stacks, instructions));

  EXPECT_STREQ(topCrates.c_str(), "MCD");
}

TEST(SupplyStacksTest, Part2) {
  const string items("JWHGRSVPNRFWTVCWVLQZJGCGCWLFZCPGHQTBJCHRPMZNLTHMCDVWPWRF");
  vector<stack<char>> stacks = GenerateStacks(9);

  AddItems(stacks, 8, items, 0, 7);
  AddItems(stacks, 7, items, 7, 8);
  AddItems(stacks, 6, items, 15, 8);

  AddItems(stacks, 5, items, 23, 6);
  AddItems(stacks, 4, items, 29, 7);
  AddItems(stacks, 3, items, 36, 4);

  AddItems(stacks, 2, items, 40, 5);
  AddItems(stacks, 1, items, 45, 8);
  AddItems(stacks, 0, items, 53, 3);

  auto instructions = ReadFile(FILE_PATH + "part1.txt");
  string topCrates(BeginCraneOperations2(stacks, instructions));

  EXPECT_STREQ(topCrates.c_str(), "CNSCZWLVT");
}