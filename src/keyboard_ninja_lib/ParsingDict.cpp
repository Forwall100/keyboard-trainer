#include <fstream>
#include <keyboard_ninja_lib/ParsingDict.hpp>
#include <string>
#include <vector>

using namespace std;

vector<string> ParsingDict(string DictPath) {
  // Создаем вектор, в котором будут храниться слова из словаря
  vector<string> dict;
  string line;

  // Открываем файл словаря
  ifstream file(DictPath);

  // Построчно читаем файл словаря и добавляем слова в вектор
  if (file.is_open()) {
    while (getline(file, line)) {
      dict.push_back(line);
    }
  }
  file.close();

  // Функция возвращает вектор со словами из словаря
  return dict;
}
