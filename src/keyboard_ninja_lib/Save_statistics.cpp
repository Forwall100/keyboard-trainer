#include <iostream>
#include <fstream>
#include <time.h>
#include <keyboard_ninja_lib/Save_statistics.hpp>

using namespace std;

float Save_statistic(int score, int wrong, int training_time)
{
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    auto year = 1900 + ltm->tm_year;
    auto month = ltm->tm_mon;
    auto day = 1 + ltm->tm_mday;
    auto hour = ltm->tm_hour;
    auto min = ltm->tm_min;

    ofstream out("./statistic.txt", ios::app);
    if (out.is_open())
    {
        out << "\n\n";
        out << "Тренировка " << day << "." << month << "." << year << " " << hour << ":" << min <<  endl;
        out << "Правильно введенные слова: " << score << endl;
        out << "НЕправильно введенные слова: " << wrong << endl;
        out << "Время тренировки: " << (training_time < 0 ? 0 : training_time) << endl;
        out << "Кол-во слов в минуту: " << (float)score / ((float)training_time / 60.0) << endl;
    }
    return (float)score / ((float)training_time / 60.0);
}