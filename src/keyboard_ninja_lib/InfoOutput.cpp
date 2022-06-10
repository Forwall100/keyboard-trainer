#include <iostream>
#include <keyboard_ninja_lib/InfoOutput.hpp>

using namespace std;
// функция получает не вход количество правильных слов, неправильных слов и
// количество секунд до конца игры
string InfoOutput(int CorrectWord, int WrongWord, int time, bool output)
{
    string array_data[3];
    array_data[0] = to_string(CorrectWord);
    array_data[1] = to_string(WrongWord);
    array_data[2]
            = to_string(time < 0 ? 0 : time); // если время становится
                                              // отрицательным - выводится 0
    string string_data = array_data[0] + array_data[1] + array_data[2];
    if (output) {
        cout << "Правильно введенные слова: " << array_data[0] << endl;
        cout << "НЕправильно введенные слова: " << array_data[1] << endl;
        cout << "Осталось времени: " << array_data[0] << " сек";
    }
    return string_data;
}
