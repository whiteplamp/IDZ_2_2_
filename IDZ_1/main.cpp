#include <iostream>
#include <fstream>
#include "library.h"
#include <ctime>

using namespace std;

int main() {
    int LenFile = 20; //Length of file name
    char NameInput[LenFile];
    char NameOutput[LenFile];
    double ResMainFunc;
    double result = 0;
    int menu = 0;// var responding for actions in menu
    while(menu!=3){
        cout << "1.Обработка последовательности из файла" << endl;
        cout << "2.Сгенерировать последовательность" << endl;
        cout << "3.Выход" << endl;
        cout << endl;
        cout << "Ваше действие:";
        cin >> menu;
        system("clear");
        if(menu == 1){
            cout << "Введите имя файла ввода:";
            cin >> NameInput;
            ifstream fin;
            fin.open(NameInput);
            ResMainFunc = MainFunc(fin,result);
            if(ResMainFunc == 0){
                ResMainFunc = result;
            }
            fin.close();
            cout << "Введите имя файла вывода:";
            cin >> NameOutput;
            ofstream fout(NameOutput);
            fout << "Файл теста: " << NameInput << endl;
            fout << ResMainFunc;
            fout.close();
        }
        else if(menu == 2){
            cout << "Введите файл вывода:" << endl;
            cin >> NameOutput;
            ofstream fout(NameOutput);
            TestFunc(fout);
            fout.close();
        }
    }
}