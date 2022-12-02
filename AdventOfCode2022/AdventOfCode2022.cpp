// AdventOfCode2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Day1/CalorieCounting.h"
using namespace std;

// for every advent of code, create a file reader that will
// 1. read line by line
// 2. parse out any inputs and store in a format that can be processed (e.g. store data contents in a class or struct if it gets more complex than strings, numbers, and booleans)


int main()
{
  CalorieCounting counter;
  auto packs = counter.ReadFile("Wicky/small_input.txt");
  cout << "pack size: " << packs.size() << endl;
  cout << "max calories: " << counter.GetMaxCalories(packs) << endl;
}

