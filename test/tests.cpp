#include <cstdlib>
#include <ctest.h>
#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/ParsingDict.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
#include <keyboard_ninja_lib/SaveStatistics.hpp>
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

CTEST(ParsingDct, test_dict_parsing) {
  vector<string> exp;
  string line;
  exp.push_back("проверка");
  exp.push_back("тест");
  exp.push_back("холодильник");
  vector<string> real = ParsingDct("test/test_dict.txt");
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

CTEST(SaveStatistic, test_wpm) {
  time_t now = time(NULL);
  tm *ltm = localtime(&now);

  // Записываем в отдельные переменные текущий год, месяц, день, час, минуту
  auto year = 1900 + ltm->tm_year;
  auto month = ltm->tm_mon;
  auto day = 1 + ltm->tm_mday;
  auto hour = ltm->tm_hour;
  auto min = ltm->tm_min;
  int score = 10, wrong = 5, training_time = 60;
  float words_per_minute = (score * 60) / training_time;
  string exp =
      "\n\nТренировка " + to_string(day) + "." + to_string(month) + "." +
      to_string(year) + " " + to_string(hour) + ":" + to_string(min) +
      " \nПравильно введенные слова: 10\nНЕправильно введенные "
      "слова: " +
      to_string(wrong) + "\nВремя тренировки: " + to_string(training_time) +
      "\nКол-во слов в минуту: " + to_string(words_per_minute) + "\n";
  string real = SaveStatistic(score, wrong, training_time);
  ASSERT_TRUE((exp == real));
  remove("./statistic.txt");
}
