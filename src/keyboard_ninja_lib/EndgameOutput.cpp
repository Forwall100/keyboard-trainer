#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <iostream>

using namespace std;

int EndGameOutput(int s, int w, int time) {
  cout << "Правильно введенные слова: " << s << endl;
  cout << "Нeправильно введенные слова: " << w << endl;
  cout << "Время тренировки: " << (time < 0 ? 0 : time) << endl;
  cout << "Кол-во слов в минуту: " << (float)s / ((float)time / 60.0) << endl;
  cout << endl << endl << endl;
  cout << "Сохранить статистику? (y/n)" << endl;
  return (float)s / ((float)time / 60.0);
}
