#pragma once

#include <string>
using namespace std;

namespace TestUtils {
  // https://stackoverflow.com/questions/15874723/how-to-open-a-file-from-the-project-in-a-native-c-unit-test-visual-studio
  static string GetDirectoryName(string path) {
    const size_t last_slash_idx = path.rfind('\\');
    if (string::npos != last_slash_idx)
    {
      return path.substr(0, last_slash_idx + 1);
    }
    return "";
  }

  static string TEST_DIRECTORY(GetDirectoryName(__FILE__));
}
