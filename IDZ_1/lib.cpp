#include "library.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int MainFunc(ifstream &fin, double &res){
    char x;
    int ret = 0;
    int k = 0;// flag of
    int l = 0; // length
    double n = 0;//count
    if (!fin) return -1;

    while (fin >> x){
        if (x >= 'a' && x <= 'z' && k == 0){
            n++;
            k++;
            l++;
        }
        else if(x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '^' || x == '*' || x == '(' || x == ')' || x == '"'){
            k = 0;
        }
        else{
            l++;
        }

    }

    if(fin.eof()){
        if(l > 0){
            res = l/n;
            ret = 0;
        }
        else {
            ret = -3;
        }
    }
    return ret;
}



void TestFunc(ofstream &fout){
    int ch_char = 20;
    int ch_int = 80;
    int length_of_file = 50;
    int T_menu = 0, T_menu_1;
    int rand_k;
    int f = 0;
    char rand_symb[36] = {'!', '@', '#', '$', '%', '^', '*', '(', ')', '"', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    while(T_menu !=3){
        cout << "Стандартные настройки генерации: Сумма частот должна равнятся 100" << endl;
        cout << "Частота появления символов: " << ch_char << endl;
        cout << "Частота появления чисел: " << ch_int << endl;
        cout << "Длина файла: " << length_of_file << endl;
        cout << "1.Изменить настройки генерации" << endl;
        cout << "2.Сгенерировать файл" << endl;
        cout << "3.Вернуться обратно" << endl;
        cout << "Действие: ";
        cin >> T_menu;
        system("clear");
        if (T_menu == 1){
            cout << "Выберите что хотите изменить" << endl;
            cout << "1.Частота появления символов: " << ch_char << endl;
            cout << "2.Частота появления чисел: " << ch_int << endl;
            cout << "3.Длина файла: " << length_of_file << endl;
            cout << "Действие: ";
            cin >> T_menu_1;
            system("clear");
            if(T_menu_1 == 1){
                cout << "Введите Частоту появления символов: ";
                cin >> ch_char;
            }
            else if(T_menu_1 == 2){
                cout << "Введите частоту появления чисел:";
                cin >> ch_int;
            }
            else if(T_menu_1 == 3){
                cout << "Введите длину файла:";
                cin >> length_of_file;
            }
            else{cout << "Ошибка ввода" << endl;}
        }
        else if(T_menu == 2){
            if(ch_char + ch_int == 100){


                srand(time(NULL));
                for(int i = 0;i < length_of_file;i++){
                    f = 1 + rand() % 100;
                    if(f <= ch_char){
                        rand_k = 1 + rand() % 36;
                        fout << rand_symb[rand_k];

                    }
                    else if(f > ch_char){
                        rand_k = 1 + rand() % 9;
                        fout << rand_k;
                    }
                }
                cout << "Процесс успешно завершен" << endl;
                system("clear");
            }
            else {
                cout << endl;
                cout << "Ошибка работы программы(Частота указана неверно)" << endl;
                system("clear");
            }
        }
    }
}