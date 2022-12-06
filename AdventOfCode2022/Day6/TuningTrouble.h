/*
  Part 1:
  - four characters are all different in a sequence = start of packet marker  
  - identify where the four most recently received characters were all different
  - report number of characters from beginning of buffer to end of the first such four character marker

  Question:
  How many characters need to be processed before the first start-of-packet marker is detected?

  sliding window problem?

*/

#pragma once
#include <string>
#include <unordered_set>

using namespace std;

namespace TuningTrouble
{
  int DetectFirstStartOfPacketMarker(const string& packet, const int size = 4)
  {
    int i = 0, j = size;
    while (j < packet.length()) {
      unordered_set<char> charSet;
      int t = i;
      while (t < j) {
        charSet.insert(packet[t++]);
      }

      if (charSet.size() == size) {
        return t;
      }
      else {
        ++i;
        j = i + size;
      }
    }

    return -1;
  }
}