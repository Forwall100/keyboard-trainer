#include <iostream>
#include <keyboard_ninja_lib/EndgameOutput.hpp>
#include <keyboard_ninja_lib/InfoOutput.hpp>
#include <keyboard_ninja_lib/Playing.hpp>
#include <keyboard_ninja_lib/RandomWord.hpp>
#include <keyboard_ninja_lib/SaveStatistic.hpp>
#include <string>
#include <time.h>
#include <vector>

int Playing(vector<string> dict, int PlayTime, int DictSize) {
  if (PlayTime <= 0) {
    return 0;
  } //прекращение работы программы, если введено отрицательное время

  int score = 0, wrong = 0, ExitFlag = 0; //переменная, отвечающая за подсчёт верных слов
  time_t StartTime = time(NULL);

  while (time(NULL) - StartTime < PlayTime and
         ExitFlag == 0) { //пока разность текущего времени и времени старта игры
                          //не будет больше, чем время, выбранное игроком для
                          //игры, программа будет работать
    system("clear");
    string NewWord =
        RandomWord(dict, DictSize); //выбор случайного слова для ввода
    InfoOutput(score, wrong,
               PlayTime - (time(NULL) -
                           StartTime)); //вызов вывода текста для отображения
                                        //актуальной информации об игре
    cout << "\n\n\n\t" << NewWord
         << "\n\n\n\n"; //вывод случайного слова, требуемого для ввода
    string InputWord;
    bool Equal =
        false; //флаг для того, чтобы в случае неверного ввода слова, игрок
               //вводил то же самое слово, а не выбиралось случайное
    while (!Equal and (time(NULL) - StartTime < PlayTime) and
           ExitFlag == 0) { //пока игрок не ввёл правильное слово и пока время
                            //не завершится и пока игрок не завершит игру
      cin >> InputWord;     //ввод слова игроком
      if (InputWord == ":q") {
        wrong--;
        ExitFlag = 1;
      } //для досрочного завершения игры (в случае, если игрок введёт слово
        //":q", игра досрочно завершится
      if (InputWord == NewWord) {
        score++;
        Equal = true; //если слово введено верно, игрок получает +1 к числу
                      //правильных слов и выбирается новое слово
      } else {
        system("clear");
        wrong++;
        InfoOutput(score, wrong, PlayTime - (time(NULL) - StartTime));
        cout << "\n\n\n\t" << NewWord << "\n\n\n\n";
      } //если слово введено неверно, флаг Equal не меняется, следовательно
        //игрок должен ввести то же самое слово
    }
    system("clear");
  }
  char choice; //для решения о сохранении статистики
  EndGameOutput(score, wrong, PlayTime);
  cin >> choice;
  if (choice == 'y') {
    SaveStatistic(score, wrong, PlayTime);
  }
  system("clear");
  return 0;
}
