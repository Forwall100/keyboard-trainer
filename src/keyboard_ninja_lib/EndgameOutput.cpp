#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>

using namespace std;

// функция получает на вход количество правильных слов, количество неправильных
// слов и количество секунд, сколько длилась тренировка
string EndGameOutput(int CorrectWord, int WrongWord, int time, bool output)
{
    // в переменной string_data происходит конкатенация строк для дальнейшего их
    // вывода в терминал и возвращения из функции для теста
    string array_data[4];
    array_data[0] = to_string(CorrectWord);
    array_data[1] = to_string(WrongWord);
    array_data[2] = to_string(
            time < 0 ? 0 : time); // если время меньше нуля - возвращается 0
    array_data[3] = to_string(
            (float)CorrectWord
            / ((float)time
               / 60.0)); // слова в минуту вычисляются по формуле:
                         // (количество слов в минуту/время тренировки)*60
    string string_data
            = array_data[0] + " " + array_data[1] + " " + array_data[2] + " " + array_data[3];
    if (output) {
        cout << "Правильно введенные слова: " << array_data[0] << endl;
        cout << "Нeправильно введенные слова: " << array_data[1] << endl;
        cout << "Время тренировки: " << array_data[2] << endl;
        cout << "Кол-во слов в минуту: " << array_data[3] << endl;
        cout << "\n\n\n\nСохранить статистику? (y/n)" << endl;
    }
    return string_data;
}
