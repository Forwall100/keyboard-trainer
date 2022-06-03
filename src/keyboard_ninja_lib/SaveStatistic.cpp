#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/SaveStatistic.hpp>
#include <string>
#include <time.h>

using namespace std;

string SaveStatistic(int score, int wrong, int training_time) {
  // создание строки, которая будет возвращаться для проверки правильности
  // работы программы в тестах
  string test_data = "";
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

  // Записываем статистику в файл и в строку для тестов
  if (out.is_open()) {
    out << "\n\n";
    test_data += "\n\n";
    out << "Тренировка " << day << "." << month << "." << year << " " << hour
        << ":" << min << endl;
    test_data += "Тренировка " + to_string(day) + "." + to_string(month) + "." +
                 to_string(year) + " " + to_string(hour) + ":" +
                 to_string(min) + " \n";
    out << "Правильно введенные слова: " << score << endl;
    test_data += "Правильно введенные слова: " + to_string(score) + "\n";
    out << "НЕправильно введенные слова: " << wrong << endl;
    test_data += "НЕправильно введенные слова: " + to_string(wrong) + "\n";
    out << "Время тренировки: " << (training_time < 0 ? 0 : training_time)
        << endl;
    test_data += "Время тренировки: " +
                 to_string((training_time < 0 ? 0 : training_time)) + "\n";
    out << "Кол-во слов в минуту: "
        << (float)score / ((float)training_time / 60.0) << endl;
    test_data += "Кол-во слов в минуту: " +
                 to_string((float)score / ((float)training_time / 60.0)) + "\n";
  }
  out.close();

  return test_data;
}
