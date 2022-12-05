/*
  
  Crate visual input

    [D]
[N] [C]
[Z] [M] [P]
 1   2   3

move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2

part 1 visual input

    [P]                 [C] [C]
    [W]         [B]     [G] [V] [V]
    [V]         [T] [Z] [J] [T] [S]
    [D] [L]     [Q] [F] [Z] [W] [R]
    [C] [N] [R] [H] [L] [Q] [F] [G]
[F] [M] [Z] [H] [G] [W] [L] [R] [H]
[R] [H] [M] [C] [P] [C] [V] [N] [W]
[W] [T] [P] [J] [C] [G] [W] [P] [J]
 1   2   3   4   5   6   7   8   9

e.g. move 1 crate from stack 2 to stack 1

input:
- given 3 stacks of crates labelled 1 2 and 3

output:
- string output CMZ (C for stack 1, M for stack 2, Z for stack 3)


Task:
after all crate move instructions are applied, determine
which crates ends up on top of each stack of crates

Part 2: twist -> there is a new crane machine that can move multiple crates at once. This has a side effect of perserving the order
we pick up multiple crates at once.. e.g. if we need to pick up 3 crates at once (ABC), then the order they get stacked on top of another stack remains the same!


*/

#pragma once
#include <stack>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

namespace SupplyStacks
{
  struct CrateMoveInstruction {
    CrateMoveInstruction(int count, int from, int to) :
      moveCount(count), sourceStackIndex(from), destStackIndex(to) {}

    ~CrateMoveInstruction() {}

    int moveCount;
    int sourceStackIndex;
    int destStackIndex;
  };

  // https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
  bool IsNumber(const string& s) {
    return !s.empty() && find_if(s.begin(), s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
  }

  vector<string> Split(const string& s, char delim) {
    vector<string> tokens;

    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delim)) {
      tokens.push_back(token);
    }

    return tokens;
  }

  CrateMoveInstruction ParseInstruction(const string& line) {
    vector<string> tokens = Split(line, ' ');
    int i = 0;
    int numbers[3]{ -1, -1, -1 };
    for (auto token : tokens) {
      if (!IsNumber(token)) {
        continue;
      }

      // crate numbers in code are 0 indexed instead of starting at 1 (as provided by the input examples)
      numbers[i++] = i == 0 ? stoi(token) : stoi(token) - 1;
    }

    return CrateMoveInstruction(numbers[0], numbers[1], numbers[2]);
  }

  vector<CrateMoveInstruction> ReadFile(const string& filePath) {
    ifstream file;
    file.open(filePath.c_str());

    vector<CrateMoveInstruction> instructions;
    string line;
    while (getline(file, line)) {
      CrateMoveInstruction instruction = ParseInstruction(line);
      instructions.push_back(instruction);
    }

    file.close();

    return instructions;
  }

  vector<stack<char>> GenerateStacks(int stackCount) {
    vector<stack<char>> stacks;
    for (int i = 0; i < stackCount; ++i) {
      stacks.push_back(stack<char>());
    }

    return stacks;
  }

  void AddItems(vector<stack<char>>& stacks, int stackIndex, const string& items, int itemIndex, int itemCount) {
    stack<char>* crateStack = &stacks[stackIndex];
    for (int i = itemIndex; i < itemIndex + itemCount; ++i) {
      crateStack->push(items[i]);
    }
  }

  void ApplyCraneOperationPart1(vector<stack<char>>& stacks, const CrateMoveInstruction& instruction) {
    const int moveCount = instruction.moveCount;
    const int sourceStack = instruction.sourceStackIndex;
    const int destStack = instruction.destStackIndex;

    for (int i = 0; i < moveCount; ++i) {
      char item = stacks[sourceStack].top();
      stacks[sourceStack].pop();
      stacks[destStack].push(item);
    }
  }

  void ApplyCraneOperationPart2(vector<stack<char>>& stacks, const CrateMoveInstruction& instruction) {
    const int moveCount = instruction.moveCount;
    const int sourceStack = instruction.sourceStackIndex;
    const int destStack = instruction.destStackIndex;

    vector<char> items;
    for (int i = 0; i < moveCount; ++i) {
      items.push_back(stacks[sourceStack].top());
      stacks[sourceStack].pop();
    }

    // preserve relative ordering of grabbing multiple items at once using the CrateMover 9001
    for (int i = items.size() - 1; i >= 0; --i) {
      stacks[destStack].push(items[i]);
    }
  }

  typedef void (*ApplyCraneOp)(vector<stack<char>>& stacks, const CrateMoveInstruction& instruction);
  string BeginCraneOperations(vector<stack<char>>& stacks, const vector<CrateMoveInstruction>& instructions, ApplyCraneOp applyCraneOp) {
    char* buf = new char[stacks.size()];

    for (auto instruction : instructions) {
      applyCraneOp(stacks, instruction);
    }

    // pick the top crate from each stack
    for (int i = 0; i < stacks.size(); ++i) {
      buf[i] = stacks[i].top();
    }

    string topCrates(buf, stacks.size());
    delete[] buf;
    return topCrates;
  }

  string BeginCraneOperations1(vector<stack<char>>& stacks, const vector<CrateMoveInstruction>& instructions) {
    return BeginCraneOperations(stacks, instructions, ApplyCraneOperationPart1);
  }

  string BeginCraneOperations2(vector<stack<char>>& stacks, const vector<CrateMoveInstruction>& instructions) {
    return BeginCraneOperations(stacks, instructions, ApplyCraneOperationPart2);
  }
}

