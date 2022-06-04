#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <string>

using namespace std;
// функция получает на вход количество правильных слов, количество неправильных
// слов и количество секунд, сколько длилась тренировка
string EndGameOutput(int CorrectWord, int WrongWord, int time) {
  // в переменной string_data происходит конкатенация строк для дальнейшего их
  // вывода в терминал и возвращения из функции для теста
  string string_data =
      "Правильно введенные слова: " + to_string(CorrectWord) +
      "\nНeправильно введенные слова: " + to_string(WrongWord) +
      "\nВремя тренировки: " +
      to_string(time < 0 ? 0
                         : time) + // если время меньше нуля - возвращается 0
      "\nКол-во слов в минуту: " +
      to_string((float)CorrectWord /
                ((float)time /
                 60.0)) + // слова в минуту вычисляются по формуле: (количество
                          // слов в минуту/время тренировки)*60
      "\n\n\n\n\nСохранить статистику? (y/n)";
  cout << string_data << endl;
  return string_data;
}
