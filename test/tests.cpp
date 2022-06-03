#include <cstdlib>
#include <ctest.h>
#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/SaveStatistics.hpp>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
#include <keyboard_ninja_lib/ParsingDict.hpp>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>

CTEST(InfoOutput, test_positive) {
  double a = 12;
  const double exp = 12;
  double real = InfoOutput(5, 10, a);
  ASSERT_DBL_NEAR(exp, real);
}
CTEST(InfoOutput, test_negative) {
  double a = -12;
  const double exp = 0;
  double real = InfoOutput(5, 10, a);
  ASSERT_DBL_NEAR(exp, real);
}

CTEST(ParsingDct, test_first_line) {
  vector<string> exp;
  string line;
  ifstream file("dict.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      exp.push_back(line);
    }
  }
  file.close();
  vector<string> real = ParsingDct();
  ASSERT_TRUE((exp == real));
}

CTEST(EndGameOutput, test_negative) {
  int w = 10, s = 10, time = 60;
  const float exp = (float)s / ((float)time / 60.0);
  double real = EndGameOutput(s, w, time);
  ASSERT_DBL_NEAR(exp, real);
}

CTEST(RandomWord, not_empty_string) {
  string empty_string = "";
  vector<string> dict;
  string line;
  ifstream file("dict.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      dict.push_back(line);
    }
  }
  file.close();
  int dSize = dict.size();
  string not_empty_string = RandomWord(dict, dSize);
  ASSERT_TRUE(empty_string != not_empty_string);
}

CTEST(SaveStatistic, test_wpm){
  int score = 10, wrong = 5, training_time = 60;
  float exp = (float)score / ((float)training_time / 60.0);
  float real = SaveStatistic(score, wrong, training_time);
  ASSERT_DBL_NEAR(exp, real);
  remove("./statistic.txt");
}
