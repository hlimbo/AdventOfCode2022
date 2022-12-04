/*
  rucksack = backpack

  each rucksack has 2 large compartments

  Rule: One Item Type per Rucksack

  Task: locate where the errors in placing the items for all rucksacks for all large compartments

  Input:
    - lowercase or uppercase english letter
    - a and A refer to different item types
    - each line represents a list of items for one rucksack
    - rucksack ALWAYS has the SAME NUMBER of items in each of the 2 compartments
    - first half of characters represent items in 1st compartment, second half of characters represent items in second compartment


  Priorities
    - lowercase item types a-z have priorities 1 to 26
    - uppercase item types A-Z have priorities 27 to 52
        * make a hashmap that maps letters to priorities

  Tl;dr task:
    find the sum of the priorities of those item types whose item type appears in both compartments of each rucksack

  Question??
    * can more than 1 item type appear in both compartments? or can I assume that only 1 item type at most appears in both compartments for each rucksack?
    * can you have duplicate item types appear in 1 rucksack? yes based on the sample input given
    * does each rucksack guarantee to hold an even number of items? if it's odd how to split?
      * I'm going to assume each rucksack is even based on the sample input given 
  

  Part 2
  * Elves divided into groups of 3
  * if 3 elves carry badge type B, then all 3 elves will have item type B in their rucksack somewhere
  * and AT MOST 2 of elves will be carrying any other item type
 
  Need to find the commom item between all 3 elves per group to determine the correct badge type...
  as the badge stickers are all out of date :/

  Goal: find the sum of priorities of those item types based on the item type that corresponds
  to the badges of each 3 elf group
  - for 3 rucksacks, we need to find the common item type among all 3 bags!
  * I'm assuming that the input I'm given is perfectly divisible by 3.. otherwise we run into further complications if that's not the case

  - to parse the input, we need to read rucksacks in groups of 3
  - for each rucksack, build an itemset
  - given 1 item set check the other 2 sets of the same group if they contain the same letter
  as the other 2 sets
  - if yes, lookup that letter (item type's) priority value and add to the sum

*/

#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace RucksackReorganization
{
  unordered_map<char, int> BuildItemMappings() {
    unordered_map<char, int> itemMappings;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int priorityIndex = 1;
    for (char letter : letters) {
      itemMappings[letter] = priorityIndex++;
    }

    return itemMappings;
  }

  vector<string> ReadFile(const string& filePath) {
    ifstream file;
    file.open(filePath.c_str());

    vector<string> lines;

    string line;
    while (getline(file, line)) {
      lines.push_back(line);
    }

    file.close();

    return lines;
  }

  bool DoesItemExist(const unordered_set<char>& items, char item) {
    return items.find(item) != items.end();
  }

  int CalculateErrorSum(const vector<string>& rucksacks) {
    const unordered_map<char, int> priorityMap(BuildItemMappings());

    int errorSum = 0;
    for (const string rucksack : rucksacks) {
      // split the rucksack in half into 2 compartments
      const size_t compartmentLength = rucksack.length() / 2;

      unordered_set<char> compartment1;
      unordered_set<char> compartment2;

      size_t compartment1Index = 0;
      size_t compartment2Index = compartmentLength;

      while (compartment1Index < compartmentLength) {
        compartment1.insert(rucksack[compartment1Index]);
        ++compartment1Index;
      }

      while (compartment2Index < rucksack.length()) {
        compartment2.insert(rucksack[compartment2Index]);
        ++compartment2Index;
      }

      for (const char item : compartment1) {
        if (DoesItemExist(compartment2, item)) {
          errorSum += priorityMap.at(item);
        }
      }
    }
    
    return errorSum;
  }

  const unordered_set<char> BuildItemSet(const string& rucksack) {
    unordered_set<char> itemSet;

    for (const char item : rucksack) {
      itemSet.insert(item);
    }

    return itemSet;
  }

  int CalculateBadgesSum(const vector<string>& rucksacks) {
    const unordered_map<char, int> priorityMap(BuildItemMappings());

    int badgesSum = 0;

    for (size_t i = 0; i < rucksacks.size(); i += 3) {
      auto itemSet1 = BuildItemSet(rucksacks[i]);
      auto itemSet2 = BuildItemSet(rucksacks[i + (size_t)1]);
      auto itemSet3 = BuildItemSet(rucksacks[i + (size_t)2]);

      for (const char item : itemSet1) {
        if (DoesItemExist(itemSet2, item) && DoesItemExist(itemSet3, item)) {
          badgesSum += priorityMap.at(item);
        }
      }
    }

    return badgesSum;
  }
}

