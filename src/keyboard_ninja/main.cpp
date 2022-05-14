#include "../keyboard_ninja_lib/EndgameOutput.hpp"
#include "../keyboard_ninja_lib/InfoOutput.hpp"
#include "../keyboard_ninja_lib/Playing.hpp"
#include "../keyboard_ninja_lib/RandomWord.hpp"
#include "../keyboard_ninja_lib/parsing_dict.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {
  srand(time(NULL));
  vector<string> dict;
  int PlayTime;
  dict = parsing_dict();
  int DictionarySize = dict.size();
  cout << "Введите время тренировки: ";
  cin >> PlayTime;
  Playing(dict, PlayTime, DictionarySize);
  return 0;
}
