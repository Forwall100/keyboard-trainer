#include <keyboard_ninja_lib/RandomWord.hpp>

using namespace std;

string RandomWord(vector<string> dict, int DictSize) {
  return dict[rand() % DictSize]; //возвращает случайное слово из числа всех
                                  //слов в словаре
}
