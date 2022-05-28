#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/Save_statistics.hpp>
#include <time.h>

using namespace std;

float Save_statistic(int score, int wrong, int training_time) {

  ofstream out("./statistic.txt", ios::app);
  if (out.is_open()) {
    out << "\n\n";
    out << "Тренировка " << endl;
    out << "Правильно введенные слова: " << score << endl;
    out << "НЕправильно введенные слова: " << wrong << endl;
    out << "Время тренировки: " << (training_time < 0 ? 0 : training_time)
        << endl;
    out << "Кол-во слов в минуту: "
        << (float)score / ((float)training_time / 60.0) << endl;
  }
  out.close();
  return (float)score / ((float)training_time / 60.0);
}
