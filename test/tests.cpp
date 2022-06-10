#include <cstdlib>
#include <ctest.h>
#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/ParsingDict.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
#include <keyboard_ninja_lib/SaveStatistic.hpp>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;
CTEST(InfoOutput,
      positive_time) { // проверка InfoOutput с положительным временем, в
                       // результате функция должна возвращать все данные с этим
                       // же временем
  int time = 12, CorrectWord = 5, WrongWord = 10;
  string exp = "Правильно введенные слова: 5\nНЕправильно введенные слова: "
               "10\nОсталось времени: 12 сек";
  string real = InfoOutput(CorrectWord, WrongWord, time, false);
  ASSERT_TRUE((exp == real));
}
CTEST(InfoOutput,
      negative_time) { // проверка InfoOutput с положительным временем, в
                       // результате функция должна возвращать все данные с
                       // нулевым временем
  int time = -12, CorrectWord = 5, WrongWord = 10;
  string exp = "Правильно введенные слова: 5\nНЕправильно введенные слова: "
               "10\nОсталось времени: 0 сек";
  string real = InfoOutput(CorrectWord, WrongWord, time, false);
  ASSERT_TRUE((exp == real));
}

CTEST(ParsingDict,
      test_dict_parsing) { // проверка функции ParsingDict, функция вызывается с
                           // путем до тестового словаря в папке test в качестве
                           // аргумента, после чего полученный словарь
                           // сравнивается с такими же значениями, которые
                           // вносятся в вектор вручную
  vector<string> exp;
  string line;
  exp.push_back("проверка");
  exp.push_back("тест");
  exp.push_back("холодильник");
  vector<string> real = ParsingDict("test/test_dict.txt");
  ASSERT_TRUE((exp == real));
}

CTEST(EndGameOutput,
      test_string) { // проверка функции EndGameOutput, полностью проверяется
                     // вывод строк в терминал
  int WrongWord = 10, CorrectWord = 10, time = 60;
  float words_per_minute = (CorrectWord * 60) / time;
  string exp = to_string(CorrectWord) + to_string(WrongWord) + to_string(time) +
               to_string(words_per_minute);

  string real = EndGameOutput(CorrectWord, WrongWord, time, false);
  ASSERT_TRUE((exp == real));
}

CTEST(
    RandomWord,
    RandomWord_in_dictionary) { // проверяется функция RandomWord на то, входит
                                // ли возвращаемое слово в используемый словарь
  vector<string> dict;
  string line;
  ifstream file("test/test_dict.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      dict.push_back(line);
    }
  }
  file.close();
  int dSize = dict.size();
  string real = RandomWord(dict, dSize);
  int flag = 0;
  for (int i = 0; i < dSize; i++) {
    if (dict[i] == real) {
      flag = 1;
    }
  }
  ASSERT_EQUAL(flag, 1);
}

CTEST(SaveStatistic, test_wpm) {
  time_t now = time(NULL);
  tm *ltm = localtime(&now);

  // Записываем в отдельные переменные текущий год, месяц, день, час, минуту
  auto year = 1900 + ltm->tm_year;
  auto month = 1 + ltm->tm_mon;
  auto day = ltm->tm_mday;
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
