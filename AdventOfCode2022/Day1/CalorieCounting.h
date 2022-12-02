/*
  12-1-2022 Day 1

  --- Day 1: Calorie Counting ---
Santa's reindeer typically eat regular reindeer food, but they need a lot of magical energy to deliver presents on Christmas. For that, their favorite snack is a special type of star fruit that only grows deep in the jungle. The Elves have brought you on their annual expedition to the grove where the fruit grows.

To supply enough magical energy, the expedition needs to retrieve a minimum of fifty stars by December 25th. Although the Elves assure you that the grove has plenty of fruit, you decide to grab any fruit you see along the way, just in case.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

The jungle must be too overgrown and difficult to navigate in vehicles or access from the air; the Elves' expedition traditionally goes on foot. As your boats approach land, the Elves begin taking inventory of their supplies. One important consideration is food - in particular, the number of Calories each Elf is carrying (your puzzle input).

The Elves take turns writing down the number of Calories contained by the various meals, snacks, rations, etc. that they've brought with them, one item per line. Each Elf separates their own inventory from the previous Elf's inventory (if any) by a blank line.

For example, suppose the Elves finish writing their items' Calories and end up with the following list:

1000
2000
3000

4000

5000
6000

7000
8000
9000

10000
This list represents the Calories of the food carried by five Elves:

The first Elf is carrying food with 1000, 2000, and 3000 Calories, a total of 6000 Calories.
The second Elf is carrying one food item with 4000 Calories.
The third Elf is carrying food with 5000 and 6000 Calories, a total of 11000 Calories.
The fourth Elf is carrying food with 7000, 8000, and 9000 Calories, a total of 24000 Calories.
The fifth Elf is carrying one food item with 10000 Calories.
In case the Elves get hungry and need extra snacks, they need to know which Elf to ask: they'd like to know how many Calories are being carried by the Elf carrying the most Calories. In the example above, this is 24000 (carried by the fourth Elf).

Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?

*/

#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class CalorieCounting
{
public:
  vector<vector<int>> ReadFile(const string& filePath) {
    ifstream file;
    file.open(filePath.c_str());

    int packIndex = 0;
    vector<vector<int>> caloriePacks;
    caloriePacks.push_back(vector<int>());

    string line;
    while (getline(file, line)) {
      if (line.empty()) {
        ++packIndex;
        caloriePacks.push_back(vector<int>());
      }
      else {
        int calories = stoi(line);
        caloriePacks[packIndex].push_back(calories);
      }
    }

    file.close();

    return caloriePacks;
  }

  int GetMaxCalories(const vector<vector<int>>& caloriePacks) {
    int maxCaloriesSum = 0;
    for (auto pack : caloriePacks) {
      int caloriesSum = accumulate(pack.begin(), pack.end(), decltype(pack)::value_type(0));
      maxCaloriesSum = max(maxCaloriesSum, caloriesSum);
    }

    return maxCaloriesSum;
  }

  vector<int> GetTop3Calories(vector<vector<int>> caloriePacks) {
    // calculate all sums, store in a list, sort in descending order, grab the first 3 elements in the list...
    // tradeoff - waste space when we could probably discard items in the list that are no longer part of the top 3 as we go through all sums...
    // we could limit the number of sum calories to 3 and if we find a calorie sum either higher than the 1st, second, or third listings,
    // remove the lowest one off the list and add the new one in
    // sort the list in descending and remove last element in vector and add new one in vector
    // m log m sort... where m is size of top3 calories

    vector<int> top3Calories;
    for (auto pack : caloriePacks) {
      int caloriesSum = accumulate(pack.begin(), pack.end(), decltype(pack)::value_type(0));
      if (top3Calories.size() < 3) {
        top3Calories.push_back(caloriesSum);
      }
      else {
        // descending order
        sort(top3Calories.begin(), top3Calories.end(), greater<int>());
        if (top3Calories[top3Calories.size() - 1] < caloriesSum) {
          top3Calories.pop_back();
          top3Calories.push_back(caloriesSum);
        }
      }
    }

    return top3Calories;
  }
};

