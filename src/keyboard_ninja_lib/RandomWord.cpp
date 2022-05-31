#include <keyboard_ninja_lib/RandomWord.hpp>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

string RandomWord(vector<string> dict, int DictSize) {
  return dict[rand() % DictSize];
}
