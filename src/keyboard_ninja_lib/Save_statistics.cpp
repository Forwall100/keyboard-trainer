#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/Save_statistics.hpp>
#include <time.h>

using namespace std;

float Save_statistic(int score, int wrong, int training_time) {
  // Получаем текущее время
  time_t now = time(NULL);
  tm *ltm = localtime(&now);

  // Записываем в отдельные переменные текущий год, месяц, день, час, минуту
  auto year = 1900 + ltm->tm_year;
  auto month = ltm->tm_mon;
  auto day = 1 + ltm->tm_mday;
  auto hour = ltm->tm_hour;
  auto min = ltm->tm_min;

  // Открывваем файл статистики
  ofstream out("./statistic.txt", ios::app);

  // Записываем статистику в файл
  if (out.is_open()) {
    out << "\n\n";
    out << "Тренировка " << day << "." << month << "." << year << " " << hour
        << ":" << min << endl;
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
