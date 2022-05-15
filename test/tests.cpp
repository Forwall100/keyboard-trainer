#include <cstdlib>
#include <ctest.h>
#include <fstream>
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

CTEST(InfoOutput, test_positive) {
  double a = 12;
  const double exp = 12;
  double real = InfoOutput(5, 10, a);
  ASSERT_DBL_NEAR(exp, real);
}
CTEST(InfoOutput, test_negative) {
  double a = -12;
  const double exp = 0;
  double real = InfoOutput(5, 10, a);
  ASSERT_DBL_NEAR(exp, real);
}

CTEST(parsing_dict, test_first_line) {
  vector<string> exp;
  string line;
  ifstream file("dict.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      exp.push_back(line);
    }
  }
  file.close();
  vector<string> real = parsing_dict();
  ASSERT_TRUE((exp == real));
}
