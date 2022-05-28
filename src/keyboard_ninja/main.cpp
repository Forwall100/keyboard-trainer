#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
#include <keyboard_ninja_lib/parsing_dict.hpp>
#include <random>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {
  srand(time(NULL));
  vector<string> dict;
  int PlayTime;
  dict = parsing_dict();
  int DictionarySize = dict.size();
  if (DictionarySize == 0) {
    cout << "Словарь пуст!!!" << endl;
    return 0;
  }
  int menu = 10;
  while (menu != 0) {
    cout << "Если вы хотите играть, введите 1" << endl;
    cout << "Если вы не хотите играть, введите 0" << endl;
    cin >> menu;
    if (menu == 1) {
      system("clear");
      cout << "Введите время тренировки: ";
      cin >> PlayTime;
      if (!cin) {
        cin.clear();
        cin.ignore(100500, '\n');
      }
      Playing(dict, PlayTime, DictionarySize);
    }
    if (menu != 0 and menu != 1) {
      system("clear");
      continue;
    }
  }
  return 0;
}
