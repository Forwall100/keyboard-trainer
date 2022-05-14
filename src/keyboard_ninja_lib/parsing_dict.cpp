#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "parsing_dict.hpp"

using namespace std;

vector<string> parsing_dict(){
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
