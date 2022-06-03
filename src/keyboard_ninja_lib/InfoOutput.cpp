#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <iostream>

using namespace std;
// функция получает не вход количество правильных слов, неправильных слов и количество секунд до конца игры
int InfoOutput(int CorrectWord, int WrongWord, int time) {
  cout << "Правильно введенные слова: " << CorrectWord << endl;
  cout << "НЕправильно введенные слова: " << WrongWord << endl;
  cout << "Осталось времени: " << (time < 0 ? 0 : time) << " сек" << endl; // если время становится отрицательным - выводится 0
  return (time < 0 ? 0 : time);
}
