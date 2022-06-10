#include <fstream>
#include <keyboard_ninja_lib/SaveStatistic.hpp>

using namespace std;

string SaveStatistic(int score, int wrong, int training_time)
{
    // создание строки, которая будет возвращаться для проверки правильности
    // работы программы в тестах
    // Получаем текущее время
    time_t now = time(NULL);
    tm* ltm = localtime(&now);

    // Записываем в отдельные переменные текущий год, месяц, день, час, минуту
    auto year = 1900 + ltm->tm_year;
    auto month = 1 + ltm->tm_mon;
    auto day = ltm->tm_mday;
    auto hour = ltm->tm_hour;
    auto min = ltm->tm_min;

    // Открывваем файл статистики
    ofstream out("./statistic.txt", ios::app);

    string string_array[5];
    string_array[0] = to_string(day) + "." + to_string(month) + "."
            + to_string(year) + " " + to_string(hour) + ":"
            + to_string(min); // запись времени тренировки с
                              // точностью до минуты
    string_array[1] = to_string(score);
    string_array[2] = to_string(wrong);
    string_array[3] = to_string((training_time < 0 ? 0 : training_time));
    string_array[4] = to_string((float)score / ((float)training_time / 60.0));
    string string_data = string_array[0] + string_array[1] + string_array[2]
            + string_array[3] + string_array[4];
    // Записываем статистику в файл и в строку для тестов
    if (out.is_open()) {
        out << "\n\nТренировка " << string_array[0] << endl;
        out << "Правильно введенные слова: " << string_array[1] << endl;
        out << "НЕправильно введенные слова: " << string_array[2] << endl;
        out << "Время тренировки: " << string_array[3] << endl;
        out << "Кол-во слов в минуту: " << string_array[4]
            << endl; // запись всех данных о тренировке
    }
    out.close();

    return string_data;
}
