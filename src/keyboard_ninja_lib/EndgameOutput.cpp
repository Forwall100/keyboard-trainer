#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
int EndGameOutput(int s, int w, int time) {
  cout << "Правильно введенные слова: " << s << endl;
  cout << "НЕправильно введенные слова: " << w << endl;
  cout << "Время тренировки: " << (time < 0 ? 0 : time) << endl;
  cout << "Кол-во слов в минуту: " << (float)s / ((float)time / 60.0) << endl;
  cout << endl << endl << endl;
  cout << "Сохранить статистику? (y/n)" << endl;
  return (float)s / ((float)time / 60.0);
}
