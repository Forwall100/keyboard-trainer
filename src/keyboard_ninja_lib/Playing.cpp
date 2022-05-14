#include "../keyboard_ninja_lib/EndgameOutput.hpp"
#include "../keyboard_ninja_lib/InfoOutput.hpp"
#include "../keyboard_ninja_lib/RandomWord.hpp"
#include "Playing.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
void Playing(vector<string> dict, int PlayTime, int DictSize) {
  int score = 0;
  int wrong = 0;
  time_t StartTime = time(NULL);
  while (time(NULL) - StartTime < PlayTime) {
    system("clear");
    string NewWord = RandomWord(dict, DictSize);
    InfoOutput(score, wrong, PlayTime - (time(NULL) - StartTime));
    cout << "\n\n\n\t" << NewWord << "\n\n\n\n";
    string InputWord;
    bool Equal = false;
    while (!Equal and (time(NULL) - StartTime < PlayTime)) {
      cin >> InputWord;
      if (InputWord == NewWord) {
        score++;
        Equal = true;
      } else {
        system("clear");
        InfoOutput(score, wrong, PlayTime - (time(NULL) - StartTime));
        cout << "\n\n\n\t" << NewWord << "\n\n\n\n";
        wrong++;
      }
    }
    system("clear");
  }

  EndGameOutput(score, wrong, PlayTime);
}
