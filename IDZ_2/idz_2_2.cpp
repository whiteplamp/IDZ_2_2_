#include <iostream>
#include <windows.h>
#include <array>
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int dly = 8;
const int dlyy = 5;

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void Interface()
{
    SetColor(11, 0);
    cout << endl << "\t\t\t\t" << "   Вводите значения, для взаимодействия с программой. " << endl << endl;

    cout << endl << "\t\t\t\t" << "(1) Для выделения памяти под массив и его заполнения ";
    cout << endl << "\t\t\t\t" << "(2) Вывод матрицы на экран ";
    cout << endl << "\t\t\t\t" << "(3) Вызов редактора матриц ";
    cout << endl << "\t\t\t\t" << "(4) Запустить алгоритм сортировки Шелла";
    cout << endl << "\t\t\t\t" << "(5) Запись матрицы в файл ";
    cout << endl << "\t\t\t\t" << "(6) Удаление матрицы ";
    cout << endl << "\t\t\t\t" << "(0) Чтобы закончить работу программы ";
}

class ArrayMatrix
{
private:
    double* key;
    double** arr;
    int size1;
    int size2;
public:
    ArrayMatrix()
    {
        size1 = 0;
        size2 = 0;
        arr = NULL;
        key = NULL;
    }
    int creative(int strok, int stolb) //Конструктор с параметрами
    {
            size1 = strok;
            size2 = stolb;
            arr = new double* [size1];
            for (int i = 0; i < size1; i++)
                arr[i] = new double[size2];
            key = new double[size1];
            return 0;
    }
    void creatmatr_hand()
    {
        this->size1 = size1;
        this->size2 = size2;
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                cin >> arr[i][j];
    }
    void creatematr_random()
    {
        this->size1 = size1;
        this->size2 = size2;
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                arr[i][j] = (rand() % 30 - 10);
    }
    int creatematr_file(string name)
    {
        ifstream fin;
        fin.open(name);
        if (!fin)
        {
            cout << "Файл не открылся" << endl;
            return -1;
        }
        fin >> size1;
        fin >> size2;
        if (size1 > 0 && size2 > 0)
        {
            arr = new double* [size1];
            for (int i = 0; i < size1; i++)
                arr[i] = new double[size2];
            key = new double[size1];
            if (size1 < 0 || size2 < 0)
            {
                return -1;
            }
            else
            {
                for (int i = 0; i < size1; i++)
                    for (int j = 0; j < size2; j++)
                        fin >> arr[i][j];
            }
            if (!fin.eof() && !fin) return -1;
            fin.close();
            return 0;
        }
        else
        {
            cout << "Некоректные размеры" << endl;
            return -2;
        }
    }
    int editor()
    {
        if (arr == NULL) return -1;
        this->size1 = size1;
        this->size2 = size2;
        int x = 0, y = 0,x_ = 0,y_ = 0, i, j;
        int t = 0;
        int down1 = 0, up1 = 7, down2 = 0, up2 = 7;
        if (up1 > size1) up1 = size1;
        if (up2 > size2) up2 = size2;

        while (t != 27)
        {
            system("cls");
            for (i = down1; i < up1; i++) 
            {
                for (j = down2; j < up2; j++) 
                {
                    if (i == x && j == y) 
                    {
                        SetColor(4,14);
                        printf("%6.2lf", arr[i][j]);
                    }
                    else 
                    {
                        SetColor(11,0);
                        printf("%6.2lf", arr[i][j]);
                    }
                }
                cout << endl;
            }

            SetColor(11, 0);
            cout << "В научном формате: ";
            cout << scientific << arr[y][x] << endl;
            cout << "Индекс: " << y << " " << x << endl;

            SetColor(10, 0);
            cout << "Движение вверх: " << char(24)<<endl;
            cout << "Движение вниз: " << char(25) << endl;
            cout << "Движение вправо: " << char(26) << endl;
            cout << "Движение влево: " << char(27) << endl;
            cout << "(Enter) для выбора элемента редактирования" << endl;
            cout << "(Tab) для перехода на какой-то нужный вам элемент" << endl;
            cout << "(Esc) для возврата в меню" << endl;

            t = _getch();

            if (t == 13)
            {
                system("cls");
                cout << "Было: "; 
                printf("%6.2lf", arr[y][x]);
                cout << "Вводите новый: " << endl;
                int time;
                cin >> time;
                int choose_editor;
                cout << "Вы лишитесь первоначального значения! Жмите Enter Если согласны или Esc, если не горите желанием это делать" << endl;
                do
                {
                    choose_editor = _getch();
                } while (choose_editor != 13 && choose_editor != 27);
                if (choose_editor == 13)
                    arr[y][x] = time;
            }
            if (t == 9) {
                int x1, y1;
                do {
                    system("cls");
                    cout << "Вводите индексы: ";
                    cin >> y1;
                    cin >> x1;
                } while (x1 < 0 || y1 < 0 || x1 >= size1 || y1 >= size2);
                while (x > x1) {
                    x--;
                    if (x == down1-1) {
                        down1--;
                        up1--;
                    }
                }
                while (x < x1) {
                    x++;
                    if (x == up1) {
                        down1++;
                        up1++;
                    }
                }
                while (y < y1) {
                    y++;
                    if (y == up2) {
                        down2++;
                        up2++;
                    }
                }
                while (y > y1) {
                    y--;
                    if (y == down2-1) {
                        down2--;
                        up2--;
                    }
                }
            }
            if (t == 72 && x != 0)
            {
                x--;
                if (x == down1-1)
                {
                    up1--;
                    down1--;
                }
            }

            if (t == 80 && x != size1-1)
            {
                x++;
                if (x == up1)
                {
                    up1++;
                    down1++;
                }
            }
            if (t == 77 && y != size2 - 1)
            {
                y++;
                if (y == up2)
                {
                    up2++;
                    down2++;
                }
            }
            if (t == 75 && y != 0)
            {
                y--;
                if (y == down2-1)
                {
                    up2--;
                    down2--;
                }
            }
        }
        system("cls");
        return 0;
    }
    int fileOP(string name1)
    {
        ofstream fout;
        fout.open(name1, ofstream::app);
        if (!fout)
        {
            cout << "Файл не открылся" << endl;
            return -1;
        }
        else
        {
            fout << size1 << " ";
            fout << size2 << " ";
            fout << endl;
            for (int i = 0; i < size1; i++)
            {
                for (int j = 0; j < size2; j++)
                    fout << arr[i][j] << setw(3);
                fout << endl;
            }
        }
        fout.close();
        return 0;
    }
    void del()
        {
        this->size1 = size1;
        this->size2 = size2;
            for (int i = 0; i < size1; i++)
            delete[] arr[i];
        delete[] arr;
        delete[] key;
        cout << "Матрица удалена" << endl;
        }
    void key_()
    {
        double sum = 0;
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
                sum = sum + abs(arr[i][j]);
            key[i] = sum;
            sum = 0;
        }
    }
    void Print()
    {
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                SetColor(1, 14);
                printf("%6.2lf", arr[i][j]);
                cout << " ";
            }
            cout << endl;
        }
        SetColor(11, 0);
        cout << "Массив ключей (в нём суммы абсолютных величин всех элементов соответствующих строк" << endl;
        for (int j = 0; j < size1; j++)
        {
            printf("%6.2lf", key[j]);
            cout << " ";
        }
        cout << endl;
    }
    friend void sort(ArrayMatrix& alg);
};
void sort(ArrayMatrix& alg)
{
    double s[alg.size1];
    int i = 0;
    double tt;
    while(i < alg.size1){
        for(int j = 0;j < alg.size2;j++){
            s[i] += abs(alg.arr[i][j]);
        }
        i++;
    }
    int j = 0;
    double dm[alg.size1];
    for (i = 1; i < alg.size1; i++)
    {
    	for(int t = 0;t < alg.size1;t++){
    		dm[t] = alg.arr[t][i];
    	}
        tt = s[i];
        j = i - 1;
        while (s[j] > tt && j >= 0) //сравнение
        {
            s[j + 1] = s[j];
            for(int t = 0; t < alg.size1;t++){
                alg.arr[t][j + 1] = alg.arr[t][j];
            }
            j--;
        }
        s[j+1] = tt;
        for(int t = 0;t < alg.size1;t++){
            alg.arr[t][j+1] = dm[t];
        }
    }
}
int main()
{
    int strok, stolb, choose,choosedel, rand_choose;
    setlocale(LC_ALL, "ru");
    ArrayMatrix matr, alg;
    bool x1 = 0;
    bool checkdel = 1;
    bool x3 = 0;
    bool x4 = 0;
    bool job1 = 0;
    string name, name1;
    int job = -1;;
    do
    {
        Interface();
        cin >> job;
        system("cls");
        if (job == 1&&job1 ==0)
        {
            cout << "Выберите вариант заполнения массива: " << endl;
            cout << "(1) Ручной ввод" << endl;
            cout << "(2) Случайными числами ввод " << endl;
            cout << "(3) Файлом ввод " << endl;
            do
            {
                cin >> choose;
            } while (choose != 1 && choose != 2 && choose != 3);
                    if (choose == 1)
                    {
                        system("cls");
                        do
                        {
                            cout << "Введите размеры массива: " << endl;
                            cin >> strok;
                            cin >> stolb;
                        } while (strok < 0 || stolb < 0);
                        matr.creative(strok, stolb);
                        cout << "Память для массива выделена!" << endl;
                        cout << "Жмите ENTER для продолжения" << endl;
                        _getch();
                        system("cls");
                        cout << "Вводите значения для массива" << endl;
                        matr.creatmatr_hand();
                        matr.key_();
                        cout << "Матрица заполнена" << endl;
                        _getch();
                        system("cls");
                        checkdel = 0;
                        x1 = 1;
                        job1 = 1;
                    }
                if (choose == 2)
                {
                    do
                    {
                        cout << "Введите размеры массива: " << endl;
                        cin >> strok;
                        cin >> stolb;
                    } while (strok < 0 || stolb < 0);
                    matr.creative(strok, stolb);
                    system("cls");
                    cout << "Память для массива выделена!" << endl;
                    cout << "Жмите ENTER для продолжения" << endl;
                    _getch();
                    system("cls");
                    matr.creatematr_random();
                    cout << "Матрица заполнена случайными числами" << endl;
                    cout << "Не желаете ли вы на неё предварительно взглянуть?" << endl << endl;
                    cout << "(1) Если да, (2) Если нет: ";
                    do
                    {
                        cin >> rand_choose;
                    } while (rand_choose != 1 && rand_choose != 2);
                    if (rand_choose == 1)
                    {
                        matr.key_();
                        matr.Print();
                    }
                    cout << "Жмите ENTER для продолжения" << endl;
                    _getch();
                    system("cls");
                    checkdel = 0;
                    x1 = 1;
                    job1 = 1;
                }
                if (choose == 3)
                {
                    cout << "Введите название файла для ввода: " << endl;
                    cin >> name;
                    int j = matr.creatematr_file(name);
                    if (j == 0)
                    {
                        matr.key_();
                        cout << "Матрица заполнена числами" << endl;
                        _getch();
                        system("cls");
                        checkdel = 0;
                        x1 = 1;
                        job1 = 1;
                    }
                }
                job = -1;
            }
        if ((job == 2) && (x1 == 1))
        {
            cout << "Наша матрица " << endl;
            matr.key_();
            matr.Print();
            cout << endl;
            cout << "Нажмите ENTER для продолжения" << endl;
            _getch();
            system("cls");
        }
        if ((job == 3) && (x1 == 1))
        {
            matr.editor();
            matr.key_();
        }
        if ((job == 4) && (x1 == 1))
        {
            int choose_shell1;
            cout << "Вы точно хотите провести сортировку?" << endl;
            cout << "(1) - Да" << endl;
            cout << "(2) - Нет" << endl;
            do
            {
                cin >> choose_shell1;
            } while (choose_shell1 != 1 && choose_shell1 != 2);
            if (choose_shell1 == 1)
            {

                    system("cls");
                    cout << endl;
                    _getch();
                    system("cls");

                _getch();
                system("cls");
                matr.key_();
                sort(matr);
                cout << "Отсортировано!" << endl;
                _getch();
                system("cls");
            }
        }
        if ((job == 5) && (x1 == 1))
        {
            cout << "Введите название файла для записи Матрицы: ";
            cin >> name1;
            matr.fileOP(name1);
            cout << "Матрица записана " << endl;
            cout << "Нажмите ENTER для продолжения " << endl;
            _getch();
            system("cls");
        }
        if ((job == 6) && (x1 == 1))
        {
            cout << "Вы уверены в том, что хотите это сделать?" << endl;
            cout << "(1) Да, удаляем" << endl;
            cout << "(2) Нет, я передумал " << endl;
            cout << "(3) Да, но давайте перед этим запишем её в файл" << endl;
            do
            {
                cin >> choosedel;
            } while (choosedel != 1 && choosedel != 2 && choosedel != 3);
            if (choosedel == 1)
            {
                matr.del();
                checkdel = 1;
                x1 = 0;
                cout << "Матрица удалена" << endl;
                _getch();
                system("cls");
                job1 = 0;
            }
            if (choosedel == 3)
            {
                cout << "Введите название файла для записи: ";
                cin >> name1;
                matr.fileOP(name1);
                cout << "Матрица записана" << endl;
                _getch();
                system("cls");
                matr.del();
                cout << "Матрица удалена" << endl;
                _getch();
                system("cls");
                checkdel = 1;
                x1 = 0;
                job1 = 0;
            }
        }

    } while (job != 0);
    if (checkdel == 0)
    {
        matr.del();
    }
    return 0;
}
