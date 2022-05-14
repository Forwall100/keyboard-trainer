#include "EndgameOutput.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
void EndGameOutput(int s, int w, int time) {
  cout << "Правильно введенные слова: " << s << endl;
  cout << "НЕправильно введенные слова: " << w << endl;
  cout << "Время тренировки: " << (time < 0 ? 0 : time) << endl;
  cout << "Кол-во слов в минуту: " << (float)s / 60 << endl;
  cout << endl << endl << endl;
  cout << "Сохранить статистику? (y/n)" << endl;
}
