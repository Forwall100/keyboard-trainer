#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <string>

using namespace std;

string EndGameOutput(int CorrectWord, int WrongWord, int time) {
  string test_data =
      "Правильно введенные слова: " + to_string(CorrectWord) +
      "\nНeправильно введенные слова: " + to_string(WrongWord) +
      "\nВремя тренировки: " + to_string(time < 0 ? 0 : time) +
      "\nКол-во слов в минуту: " + to_string((float)CorrectWord / ((float)time / 60.0)) +
      "\n";

  cout << "Правильно введенные слова: " << CorrectWord << endl;
  cout << "Нeправильно введенные слова: " << WrongWord << endl;
  cout << "Время тренировки: " << (time < 0 ? 0 : time) << endl;
  cout << "Кол-во слов в минуту: " << (float)CorrectWord / ((float)time / 60.0) << endl;
  cout << endl << endl << endl;
  cout << "Сохранить статистику? (y/n)" << endl;
  return test_data;
}
