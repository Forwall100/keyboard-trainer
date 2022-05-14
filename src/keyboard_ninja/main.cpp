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

void InfoOutput(int s, int w, int time){
	cout << "Right: " << s << endl;
	cout << "Wrong: " << w << endl;
	cout << "Time left: " << time << endl;
}

void Playing(vector<string> dict, int PlayTime, int DictSize) {
  int score = 0;
  int wrong = 0;
  time_t StartTime = time(NULL);
  while (time(NULL) - StartTime < PlayTime) {
    string NewWord = RandomWord(dict, DictSize);
    InfoOutput(score, wrong, PlayTime - (time(NULL) - StartTime));
    cout << "\n\n\n\t" << NewWord << "\n\n\n\n";
    string InputWord;
    bool Equal = false;
    while (!Equal and(time(NULL) - StartTime < PlayTime)) {
      cin >> InputWord;
      if (InputWord == NewWord) {
        score++;
        Equal = true;
      } else {
        cout << "Try again\n";
        wrong++;
      }
    }
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
