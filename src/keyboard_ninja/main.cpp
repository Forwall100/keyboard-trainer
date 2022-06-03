#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/ParsingDict.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
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
  dict = parsing_dict(); //парсинг словаря в вектор dict

  int PlayTime; //перменная, отвечающая за время игры
  int menu;
  int DictionarySize = dict.size(); //переменная, обозначающая размер словаря

  if (DictionarySize == 0) {
    cout << "Файл dict.txt пуст" << endl;
    return 0; //вывод ошибки в случае, если словарь окажется пустым
  }

  while (menu != 0) {
    cout << "Если вы хотите играть, введите 1" << endl;
    cout << "Если вы не хотите играть, введите 0" << endl;
    cin >> menu; //пользовать делает выбор в меню
    if (menu == 1) {
      system("clear"); //очистка консоли
      cout << "Введите время тренировки (сек.): ";
      cin >> PlayTime; //ввод времени
      if (!cin) {
        cin.clear();
        cin.ignore(100000, '\n');
      } //для игнорирования букв или других символов
      Playing(dict, PlayTime, DictionarySize);
    }
    if (menu != 0 and menu != 1) {
      system("clear");
      continue;
    } //в случае, если пользователь ввёл не то, что от него требуют в меню,
      //программа переспрашивает его
  }
  return 0;
}
