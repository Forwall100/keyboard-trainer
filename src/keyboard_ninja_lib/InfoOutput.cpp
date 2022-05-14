#include "InfoOutput.hpp"
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;

void InfoOutput(int s, int w, int time) {
  cout << "Правильно введенные слова: " << s << endl;
  cout << "НЕправильно введенные слова: " << w << endl;
  cout << "Осталось времени: " << (time < 0 ? 0 : time) << endl;
}
