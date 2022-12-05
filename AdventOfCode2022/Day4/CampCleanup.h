/*
  Elves need to clean up the camp!

  - Each section has a unique ID number
  - each elf is assigned a range of section IDs

  * Many of the elves section assignments OVERLAP!
  
  Input:
  List of section assignments for each pair
  * first element (first elf assigned a range of sections to clean)
  * second element (second elf assigned a range of sections to clean)
 
 * Some elf pairs have no overlapping ranges while other
 * elf pairs do!
 
 * some pairs may have an elf where their assignments
 * fully contain the other e.g. 2-8 fully contains 3-7
 * In pairs where 1 assignment fully contains the other
 *  one elf in the pair would be exclusively cleaning sections their partner will already be cleaning to avoid duplicated efforts


 Question:
 * How many assignment pairs does one range fully contain the other?
 
 A range of assignments X fully contains a range of assignments Y if
    X.low <= Y.low <= Y.high <= X.high

 for every pair of elves, check if X fully contains Y or Y fully contains X
  * if either are true, increment counter by 1
  * if both are false, skip onto the next pair of elves to evaluate

*/

#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace CampCleanup
{
  vector<string> Split(const string& s, char delim) {
    vector<string> tokens;

    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delim)) {
      tokens.push_back(token);
    }

    return tokens;
  }

  struct Range
  {
    Range(int low, int high) {
      this->low = low;
      this->high = high;
    }

    ~Range() {}

    int low;
    int high;
  };

  vector<Range> ReadFile(const string& filePath) {
    ifstream file;
    file.open(filePath.c_str());

    vector<Range> ranges;
    string line;
    while (getline(file, line)) {
      auto rangePair = Split(line, ',');
      auto elfRange1 = Split(rangePair[0], '-');
      auto elfRange2 = Split(rangePair[1], '-');
      
      ranges.push_back(Range(stoi(elfRange1[0]), stoi(elfRange1[1])));
      ranges.push_back(Range(stoi(elfRange2[0]), stoi(elfRange2[1])));
    }


    file.close();

    return ranges;
  }

  typedef bool (*OverlapCheck)(const Range& e1, const Range& e2);
  int GetOverlapPairs(const vector<Range>& ranges, OverlapCheck overlapCheck) {
    int count = 0;

    for (int i = 0; i < ranges.size(); i += 2) {
      const Range e1(ranges.at(i));
      const Range e2(ranges.at(i + 1));

      if (overlapCheck(e1, e2)) {
        ++count;
      }
    }

    return count;
  }

  // assumption low is always less than or equal to high
  bool IsFullyOverlapping(const Range& e1, const Range& e2) {
    return (e1.low <= e2.low && e2.high <= e1.high) || (e2.low <= e1.low && e1.high <= e2.high);
  }

  // assumption low is always less than or equal to high
  bool IsOverlapping(const Range& e1, const Range& e2) {
    return !(e1.high < e2.low || e1.low > e2.high);
  }

  int GetFullOverlapCleanAssignmentPairs(const vector<Range>& ranges) {
    return GetOverlapPairs(ranges, &IsFullyOverlapping);
  }

  int GetOverlapCleanAssignmentPairs(const vector<Range>& ranges) {
    return GetOverlapPairs(ranges, &IsOverlapping);
  }
}

