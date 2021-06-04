#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    char data;
    Node* pNext;
};
class stackList
{
private:
    Node* top;
public:
    /*Стек на списОчке. Тут единственное что-то новое это "->" но не бойтесь - это функция для обращения в приватное поле*/
    stackList()
    {
        top = nullptr;
    }
    void clear()
    {
        Node* temp;
        while (top != nullptr)
        {
            temp = top; //Сделали временную ноду, чтобы не потерять указатель следующего элемента
            top = top->pNext; //перешли на следующий элемент
            delete temp; //удалили
        }
    }
    ~stackList()
    {
        clear(); //тут no comments
    }

    bool isEmpty()
    {
        return top == nullptr; //тут тоже
    }

    int _size(){
        int k = 0;
        Node* length = top;
        while(length && length->pNext != nullptr){
            k++;
            length = length->pNext;
        }
        return k;
    }

    char take()
    {
        char value = top->data; //берём поле данных у ноды
        Node* temp = top; //создаём новую опять же, чтобы не потерять указатели
        top = top->pNext; //переходим на другой элемент
        delete temp; //удаляем его
        return value; //возвращаем значение
    }
    void put(char value)
    {
        Node* temp; //Здесь нужна для качественной работы т.к поле ноды класса в привате и просто так с другим типо работать не будет
        temp = new Node; //создаём новую ноду
        //проверка, если память не выделилась
        temp->data = value;//ставим значение в поле данных
        temp->pNext = top;//переставляем указатель
        top = temp;//вписываем значение в поле данных
    }
    char check()
    {
        char value = top->data; //просмотр верхнего элемента
        return value;
    }

    void output(){
        Node* kek = top;
        while(kek){
            cout << kek->data << " ";
            kek = kek->pNext;
        }
        cout << endl;
    }

    void f_output(){
        ofstream fout;
        string file;
        cout << "Ввдеите имя файла: ";
        cin >> file;
        fout.open(file);
        Node* kek = top;
        while(kek){
            fout << kek->data << " ";
            kek = kek->pNext;
        }
        fout << endl;
    }
};


void exercise(stackList &s, stackList &f, int n){
    char el;
    for(int i = 0;i < n; i++){
        el = s.take();
        f.put('"');
        f.put(el);
    }
    f.put('"');
}

int main() {
    int n;
    char x;
    int exit_flag;
    bool flag = false;
    stackList stack;
    stackList stack1;
    string file = "output.txt";
    do{
        cout << "1.Создать стек вручную" << endl;
        cout << "2.Создать очередь из файла " << endl;
        cout << "3.Выполнить задание " << endl;
        cout << "4.Вывод очереди" << endl;
        cout << "5.Сохранить очередь в файл" << endl;
        cout << "6.Выход" << endl;
        cout << "Ваши действия: "<< endl;
        cin >> exit_flag;

        if (exit_flag == 1){
            system("cls");
            cout << "Введите размер стека: ";
            cin >> n;
            cout << "Введите стек" << endl;
            for (int i = 0;i < n;i++){
                cin >> x;
                stack.put(x);
            }
            flag = true;
        }
        else if(exit_flag == 2){
            system("clear");
            ifstream fin;
            fin.open("/home/yan/Рабочий стол/Individual-Homework-main/Sonya/IDZ_3/input.txt");
            fin >> n;
            for(int i = 0;i < n;i++){
                fin >> x;
                stack.put(x);
            }
            fin.close();
            flag = true;

        }
        else if(exit_flag == 3) {
            if (flag) {
                system("cls");
                exercise(stack, stack1, n);
            }
            else {
                cout << "Error" << endl;
                system("pause");
                return 0;
            }
        }

        else if(exit_flag == 4){
            if(flag){
                stack.output();
                stack1.output();
            }
        }

        else if(exit_flag == 5){
            if(flag){
                stack.f_output();
                stack1.f_output();
            }
        }
    } while(exit_flag!=6);

    return 0;

}

