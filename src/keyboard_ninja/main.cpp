#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
#include <keyboard_ninja_lib/ParsingDict.hpp>
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
  dict = parsing_dict();

  int PlayTime;
  int menu;
  int DictionarySize = dict.size();

  if (DictionarySize == 0) {
    cout << "Файл dict.txt пуст" << endl;
    return 0;
  }

  while (menu != 0) {
    cout << "Если вы хотите играть, введите 1" << endl;
    cout << "Если вы не хотите играть, введите 0" << endl;
    cin >> menu;
    if (menu == 1) {
      system("clear");
      cout << "Введите время тренировки (сек.): ";
      cin >> PlayTime;
      if (!cin) {
        cin.clear();
        cin.ignore(100000, '\n');
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
