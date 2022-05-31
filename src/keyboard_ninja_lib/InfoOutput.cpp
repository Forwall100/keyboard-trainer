#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <iostream>

using namespace std;

int InfoOutput(int s, int w, int time) {
  cout << "Правильно введенные слова: " << s << endl;
  cout << "НЕправильно введенные слова: " << w << endl;
  cout << "Осталось времени: " << (time < 0 ? 0 : time) << " сек" << endl;
  return (time < 0 ? 0 : time);
}
