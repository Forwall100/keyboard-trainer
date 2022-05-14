#include "../keyboard_ninja_lib/parsing_dict.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;


void Playing(vector<string> dict, int PlayTime) {
  time_t StartTime = time(NULL);
  int i = 0;
  while (time(NULL) - StartTime < PlayTime) {
    
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
  Playing(dict, PlayTime);
  return 0;
}
