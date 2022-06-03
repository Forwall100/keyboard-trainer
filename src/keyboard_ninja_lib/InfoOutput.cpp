#include <iostream>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <string>

using namespace std;
// функция получает не вход количество правильных слов, неправильных слов и
// количество секунд до конца игры
string InfoOutput(int CorrectWord, int WrongWord, int time) {
  string string_data =
      "Правильно введенные слова: " + to_string(CorrectWord) +
      "\nНЕправильно введенные слова: " + to_string(WrongWord) +
      "\nОсталось времени: " + to_string(time < 0 ? 0 : time) +
      " сек"; // если время становится отрицательным - выводится 0
  cout << string_data << endl;
  return string_data;
}
