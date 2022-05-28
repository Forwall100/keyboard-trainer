#include <fstream>
#include <iostream>
#include <keyboard_ninja_lib/parsing_dict.hpp>
#include <string>
#include <vector>

using namespace std;

vector<string> parsing_dict() {
  vector<string> dict;
  string line;
  ifstream file("./dict.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      dict.push_back(line);
    }
  }
  file.close();
  return dict;
}
