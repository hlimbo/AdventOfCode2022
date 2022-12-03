//  rock beats scissors, scissors beat paper, and paper beats rock
// if tie, round ends in a draw (same shape picked)

/*
  Input format:
  1st column is what opponent will play
  
    A = Rock
    B = Paper
    C = Scissors
  
  2nd column must be what I play in response

    X = Rock
    Y = Paper
    Z = Scissors

  Winner = player with highest score
  total score = sum of my scores per round

  score for winning round is based on shape I pick
  1 = rock A
  2 = paper B
  3 = scissors C
  score_round = shape_score + outcome_round_score (0 if I lose and 3 if I draw, and 6 if I win)

  Sub problems
  * can use a dictionary to map hand shape to score for me
  * can use a dictionary to map hand shape to score for opponent
  * need a function to calculate my score for a round
  * * inputs include my selection
  * * opponent selection
  * function to calculate if I win, lose, or draw (return score)
  * 
  
  Question: what would be my total score if every move is made exactly based on strategy guide?

  Part 2:

  X = need to lose
  Y = need to end in a draw
  Z = need to win

*/

#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

namespace RPS 
{
  unordered_map<char, int> opponentHandMap
  { 
    { 'A', 1 }, 
    { 'B', 2 }, 
    { 'C', 3 }, 
  };

  unordered_map<char, int> myHandMap
  { 
    { 'X', 1 }, 
    { 'Y', 2 }, 
    { 'Z', 3 }, 
  };

  // W = win, L = lose, T = tie
  unordered_map<char, int> outcomeMap { { 'W', 6 }, { 'L', 0 }, { 'T', 3 }};

  typedef int (*calculateRoundFn)(const vector<char>& hands, const unordered_map<char, int>& myHandMap, const unordered_map<char, int>& opponentHandMap, const unordered_map<char, int>& outcomeMap);
  int calculateStrategyScoreInternal(const vector<vector<char>>& rounds, calculateRoundFn calculateRound) {
    int totalScore = 0;

    for (const vector<char> hands : rounds) {
      totalScore += calculateRound(hands, myHandMap, opponentHandMap, outcomeMap);
    }

    return totalScore;
  }

  int calculateOutcome(const vector<char>& hands, const unordered_map<char, int>& myHandMap, const unordered_map<char, int>& opponentHandMap, const unordered_map<char, int>& outcomeMap) {
    const char opponentHand = hands[0];
    const char myHand = hands[1];

    int score = 0;
    const int myHandScore = myHandMap.at(myHand);

    // tie
    if ((opponentHand == 'A' && myHand == 'X') ||
      (opponentHand == 'B' && myHand == 'Y') ||
      (opponentHand == 'C' && myHand == 'Z')) {
      score = outcomeMap.at('T') + myHandScore;
    }

    // rock beats scissors
    else if (opponentHand == 'A' && myHand == 'Z') {
      score = outcomeMap.at('L') + myHandScore;
    }
    else if (opponentHand == 'C' && myHand == 'X') {
      score = outcomeMap.at('W') + myHandScore;
    }
    // scissors beats paper
    else if (opponentHand == 'C' && myHand == 'Y') {
      score = outcomeMap.at('L') + myHandScore;
    }
    else if (opponentHand == 'B' && myHand == 'Z') {
      score = outcomeMap.at('W') + myHandScore;
    }
    // paper beats rock
    else if (opponentHand == 'B' && myHand == 'X') {
      score = outcomeMap.at('L') + myHandScore;
    }
    else if (opponentHand == 'A' && myHand == 'Y') {
      score = outcomeMap.at('W') + myHandScore;
    }

    return score;
  }

  /*
    A = Rock
    B = Paper
    C = Scissors

    X = need to lose
    Y = need to end in a draw
    Z = need to win
  */
  int calculateOutcomePart2(const vector<char>& hands, const unordered_map<char, int>& handMap, const unordered_map<char, int>& opponentHandMap, const unordered_map<char, int>& outcomeMap) {
    const char opponentHand = hands[0];
    const char outcome = hands[1];
    int score = 0;

    // tie
    if (outcome == 'Y') {
      score = outcomeMap.at('T') + opponentHandMap.at(opponentHand);
    }
    // lose
    else if (outcome == 'X') {
      if (opponentHand == 'A') {
        score = outcomeMap.at('L') + opponentHandMap.at('C');
      }
      else if (opponentHand == 'B') {
        score = outcomeMap.at('L') + opponentHandMap.at('A');
      }
      else {
        score = outcomeMap.at('L') + opponentHandMap.at('B');
      }
    }
    // win
    else if (outcome == 'Z') {
      if (opponentHand == 'A') {
        score = outcomeMap.at('W') + opponentHandMap.at('B');
      }
      else if (opponentHand == 'B') {
        score = outcomeMap.at('W') + opponentHandMap.at('C');
      }
      else {
        score = outcomeMap.at('W') + opponentHandMap.at('A');
      }
    }

    return score;
  }

  int calculateStrategyScore(const vector<vector<char>>& rounds) {
    return calculateStrategyScoreInternal(rounds, &calculateOutcome);
  }

  int calculateStrategyScore2(const vector<vector<char>>& rounds) {
    return calculateStrategyScoreInternal(rounds, &calculateOutcomePart2);
  }

  vector<char> split(const string& s, char delim) {
    vector<char> tokens;

    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delim)) {
      tokens.push_back(token[0]);
    }

    return tokens;
  }

  vector<vector<char>> ReadFile(const string& filePath) {
    vector<vector<char>> strategyGuide;

    ifstream file;
    file.open(filePath.c_str());

    string line;
    while (getline(file, line)) {
      vector<char> round = split(line, ' ');
      strategyGuide.push_back(round);
    }

    file.close();

    return strategyGuide;
  }
}


