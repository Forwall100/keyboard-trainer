#include <fstream>
#include <keyboard_ninja_lib/SaveStatistic.hpp>

using namespace std;

string SaveStatistic(int score, int wrong, int training_time) {
  // создание строки, которая будет возвращаться для проверки правильности
  // работы программы в тестах
  string string_data = "";
  // Получаем текущее время
  time_t now = time(NULL);
  tm *ltm = localtime(&now);

  // Записываем в отдельные переменные текущий год, месяц, день, час, минуту
  auto year = 1900 + ltm->tm_year;
  auto month = 1 + ltm->tm_mon;
  auto day = ltm->tm_mday;
  auto hour = ltm->tm_hour;
  auto min = ltm->tm_min;

  // Открывваем файл статистики
  ofstream out("./statistic.txt", ios::app);

  // Записываем статистику в файл и в строку для тестов
  if (out.is_open()) {
    string_data = "\n\nТренировка " + to_string(day) + "." + to_string(month) +
                  "." + to_string(year) + " " + to_string(hour) + ":" +
                  to_string(min) +
                  " \n" + // запись слова "тренировка" и времени тренировки с
                          // точностью до минуты
                  "Правильно введенные слова: " + to_string(score) + "\n" +
                  "НЕправильно введенные слова: " + to_string(wrong) + "\n" +
                  "Время тренировки: " +
                  to_string((training_time < 0 ? 0 : training_time)) + "\n" +
                  "Кол-во слов в минуту: " +
                  to_string((float)score / ((float)training_time / 60.0)) +
                  "\n"; // запись всех данных о тренировке
    out << string_data; // запись в файл
  }
  out.close();

  return string_data;
}
