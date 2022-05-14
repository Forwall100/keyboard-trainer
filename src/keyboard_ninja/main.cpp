#include "../keyboard_ninja_lib/parsing_dict.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

string RandomWord(vector<string> dict, int DictSize) {
  return dict[rand() % DictSize];
}
void Playing(vector<string> dict, int PlayTime, int DictSize) {
  while (time(NULL) - StartTime < PlayTime) {
    string NewWord = RandomWord(dict, DictSize);
    cout << "\n\n\n\t" << NewWord << "\n\n\n\n";
    sleep(1);
  }
}
int main() {
  srand(time(NULL));
  vector<string> dict;
  int PlayTime;
  dict = parsing_dict();
  int DictionarySize = dict.size();
  cout << DictionarySize << endl;
  cin >> PlayTime;
  Playing(dict, PlayTime, DictionarySize);
  return 0;
}
