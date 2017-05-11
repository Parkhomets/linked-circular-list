#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
class List{
public:
    List():Head(NULL),Tail(NULL),size(0){};
    ~List();
    struct Node{
        T element;
        Node *Next;
    };
    Node *Head, *Tail;
    void Add(T element);
    void Show();
    void Ready_List(const char *);
    int Search(T petr);
    void Concatination(List<T> lst);
    void Concat(List <T> lst);
    void Sort();
    void Division(List<T> lst, List<T> lstt, T petr);
    int size;
};
class Student{
    public:
    string surname;
    string name;
    string patronymic;
    string group;
    bool operator==(Student& pumba){
        return pumba.name == name && pumba.surname == surname && pumba.patronymic == patronymic && pumba.group == group;
    }
    friend ostream& operator<<(ostream& os, Student& petr){
        os << petr.surname << " " << petr.name << " " << petr.patronymic << " " << petr.group << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Student& petr){
        is >> petr.surname;
        is >> petr.name;
        is >> petr.patronymic;
        is >> petr.group;
        return is;
    }
        void Show();
        string Ref();
};
class Professors{
    public:
    string surname;
    string name;
    string patronymic;
    string subject;
    bool operator==(Professors& pumba){
        return pumba.name == name && pumba.surname == surname && pumba.patronymic == patronymic && pumba.subject == subject;
    }
    friend ostream& operator<<(ostream& os, Professors& petr){
        os << petr.surname << " " << petr.name << " " << petr.patronymic << " " << petr.subject << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Professors& petr){
        is >> petr.surname;
        is >> petr.name;
        is >> petr.patronymic;
        is >> petr.subject;
        return is;
    }

        void Show();
        string Ref();
};
class Functions{
public:
    string Name;
    void (*func)(void);
    void Show();
    void ToDo();
};
void Functions :: ToDo(){
    func();
}

template <typename T>
void List <T> :: Concatination(List <T> lst){
    Node *tempHead = Head;
    int var = this->size;
    while (var != 1)
    {
        tempHead = tempHead->Next;
        var--;
    }
    tempHead->Next = lst.Head;
    var = lst.size;
    while (var != 0)
    {
        tempHead = tempHead->Next;
        var--;
    }
    tempHead->Next = this->Head;
    this->size +=lst.size;
}
template <typename T>
void List <T> :: Concat(List <T> lst){
    Node *tempHead = Tail;
    Node *tempHead1 = Head;
    tempHead->Next = lst.Head;
    lst.Tail->Next = tempHead1;
    this->size = this->size + lst.size;
}

template <typename T>
void List <T> :: Division(List <T> lst, List <T> lstt, T petr){
    Node *tempHead = Head;
    int var = 0;
    while (var++ < size)
    {
        if (tempHead->element.Ref() == petr.Ref()){
            lst.Add(tempHead->element);
        }else{
            lstt.Add(tempHead->element);
        }
        tempHead = tempHead->Next;
    }
    lst.Show();
    cout << endl;
}
template <typename T>
List <T> :: ~List(){
    while (size!=0){
        Node *temp = Head->Next;    //select the active item
        delete Head;                //delete the active item
        Head = temp;                //displace the pointer
        size--;
    }
}
template <typename T>
void List <T> :: Add(T element){
    size++;
    Node *temp = new Node;      //allocate memory for the new list node
    temp->Next = Head;          //short circuit
    temp->element = element;
    if (Head!=NULL){            //if list is not empty
        Tail->Next = temp;      //put the new node at the end
        Tail = temp;            //Do newly added node active
    }
    else{                       //if list is empty
        Head = Tail = temp;     //the new element becomes the beginning and end, and active, that is the only
    }
}
template <typename T>
void List <T> :: Show(){
    Node *tempHead = Head;      //put the pointer to the first element
    int temp = size;             //set up a temporary variable for convenience of output
    int counter = 1;
    while (temp!=0){
        cout << counter << " ";
        tempHead->element.Show();
        tempHead = tempHead->Next; //put the pointer to the next element
        temp--; counter++;        //reduce the counter
    }
    cout << endl;
}
void Student :: Show(){
    cout<<surname<<" "<<name<<" "<<patronymic<<" "<<group<<endl;
}
void Functions :: Show(){
    cout << Name << endl;
}
string Student :: Ref(){
    return group;
}
void Professors :: Show(){
    cout<<surname<<" "<<name<<" "<<patronymic<<" "<<subject<<endl;
}
string Professors :: Ref(){
    return subject;
}

template <typename T>
int List <T> :: Search(T petr){
    int var = 0;
    Node *temp = this->Head;
    while (var++ < size)
    {
        if (petr.surname == temp->element.surname){
                cout << var << " ";
                cout << temp->element;
                return var;
            }
        temp = temp->Next;
    }
}
template <typename T>
void List <T>::Ready_List(const char* filename){
    T petr;

    ifstream inFile(filename ,ios::in);
    if (inFile.is_open())
        while (!inFile.eof())
        {
            inFile >> petr;
            this->Add(petr);
        }else{
        cout << "\t\t\t\tFile doesn't open!!!" << endl;
        exit(0);
        }
    inFile.close();
}
template <typename T>
void List <T> :: Sort(){
    Node *tempHead1 = Head;
    Node *tempHead2 = tempHead1->Next;
    Node *tempHeadVar = new Node;
    int var = this->size-1, var1 = this->size-1;

    while (var1 != 0){
    var = this->size-1;
        while (var != 0)
        {
            if (tempHead1->element.surname > tempHead2->element.surname)
            {
                tempHeadVar->element = tempHead1->element;
                tempHead1->element = tempHead2->element;
                tempHead2->element = tempHeadVar->element;
                tempHead1 = tempHead2;
                tempHead2 = tempHeadVar;
                tempHead2 = tempHead1->Next;
            }else{
                tempHead1 = tempHead1->Next;
                tempHead2 = tempHead1->Next;
            }
            var--;
        }
        tempHead1 = tempHead1->Next;
        tempHead2 = tempHead1->Next;
        var1--;
    }
}


void squareFoo(double x){
    cout << "Это функция извлечения корня.";
    cout << "Корень из" << " " << x << " это " << sqrt(x) << endl;
}
void powFoo(double x, double y){
    cout << "Это Функция возведения в степень.";
    cout << x << " в степени " << y << " это "<< pow(x, y) << endl;
}
void truncFoo(double x){
    cout << "Это функция обрезания дробной части. Введите действительное число:";
    cout <<"Ваше число " << x << " без дробной части это " << trunc(x)<< endl;
}
void expFoo(double x){
    cout << "Это функция возведения экспоненты в степень.";
    cout << "Экспонента в степени " << x << " это " <<exp(x) << endl;
}

void Test_Ready_List(){
    List <Student> Stud1, Stud2;
    Student petr;

    cout << "\t\t\t\tTesting the function ReadyList..."<< endl;
    Stud1.Ready_List("ForTestReadyList.txt");
    petr.name = "Азамат";
    petr.surname = "Султанов";
    petr.group = "Б16505";
    petr.patronymic = "Азаматович";
    Stud2.Add(petr);
    petr.name = "Егор";
    petr.surname = "Козин";
    petr.group = "Б16505";
    petr.patronymic = "Егорович";
    Stud2.Add(petr);
    petr.name = "Владимир";
    petr.surname = "Свинин";
    petr.group = "Б16505";
    petr.patronymic = "Владимирович";
    Stud2.Add(petr);
    int p = 0;
    if (Stud1.Head->element == Stud2.Head->element)
        p++;
    if (Stud1.Head->Next->element == Stud2.Head->Next->element)
        p++;
    if (Stud1.Head->Next->Next->element == Stud2.Head->Next->Next->element)
        p++;
    if (p == 3){
        cout << "\t\t\t\t\t\tOK" << endl << endl;;
    }else{
        cout << "\t\t\t\t\t\tERROR" << endl;
        cout << "Received:" << endl;
        Stud1.Show();
        cout << "Expected:" << endl;
        Stud2.Show();
        cout << endl << endl;
    }
}
void Test_Sort(){
    List <Student> Stud1, Stud2;
    Student petr;

    cout << "\t\t\t\tTesting the function Sort..."<< endl;
    Stud1.Ready_List("ForTestSort1.txt");
    Stud1.Sort();
    Stud2.Ready_List("ForTestSort2.txt");
    int p = 0;
    if (Stud1.Head->element == Stud2.Head->element)
        p++;
    if (Stud1.Head->Next->element == Stud2.Head->Next->element)
        p++;
    if (Stud1.Head->Next->Next->element == Stud2.Head->Next->Next->element)
        p++;
    if (p == 3){
        cout << "\t\t\t\t\t\tOK" << endl << endl;
    }else{
        cout << "\t\t\t\t\t\tERROR" << endl;
        cout << "Received:" << endl;
        Stud1.Show();
        cout << "Expected:" << endl;
        Stud2.Show();
        cout << endl << endl;
    }
}
void Test_Concat(){
    List <Student> Stud1, Stud2, Stud3, Stud4, Stud5;
    Student petr;

    cout << "\t\t\t\tTesting the function Concat..."<< endl;
    Stud1.Ready_List("ForTestConcat1.txt");
    Stud2.Ready_List("ForTestConcat2.txt");
    Stud3.Ready_List("ForTestConcat3.txt");
    Stud1.Show();
    Stud2.Show();
    Stud1.Concat(Stud2);
    Stud1.Show();



    int p = 0;

    if (Stud1.Head->element == Stud3.Head->element)
        p++;
    if (Stud1.Head->Next->element == Stud3.Head->Next->element)
        p++;
    if (Stud1.Head->Next->Next->element == Stud3.Head->Next->Next->element)
        p++;
    if (Stud1.Head->Next->Next->Next->element == Stud3.Head->Next->Next->Next->element)
        p++;
    if (Stud1.Head->Next->Next->Next->Next->element == Stud3.Head->Next->Next->Next->Next->element)
        p++;
    if (Stud1.Head->Next->Next->Next->Next->Next->element == Stud3.Head->Next->Next->Next->Next->Next->element)
        p++;
    if (p == 6){
        cout << "\t\t\t\t\t\tOK" << endl;
    }else{
        cout << "\t\t\t\t\t\tERROR" << endl;
        cout << "Received:" << endl;
        Stud3.Show();
    }
}
void Test_Search(){
    List <Student> Stud1, Stud2;
    Student petr;
    cout << "\t\t\t\tTesting the function of Search" << endl;
    Stud1.Ready_List("WorkList.txt");
    petr.name = "Павел";
    petr.patronymic = "Петрович";
    petr.surname = "Пархомец";
    petr.group = "Б16505";
    cout << "Searching: \n10 Пархомец Павел Петрович Б16505..." << endl;
    cout << "Have been searched:"<<endl;
    if (Stud1.Search(petr) == 10){
        cout << "\t\t\t\t\t\tOK" << endl;
    }else{
        cout << "\t\t\t\t\tERROR" << endl;
        cout << "Expected:";
        cout << "10 " << petr;
        cout << "Received:";
        Stud1.Search(petr);
    }
}
void Test_Division(){
    List <Student> Stud1, Stud2, Stud3, Stud4, Stud5;
    Student petr;
    petr.name = "Иван";
    petr.patronymic = "Романович";
    petr.surname = "Бухтияров";
    petr.group = "Б16511";
    Stud1.Ready_List("ForTestDivision1.txt");
    Stud1.Division(Stud2, Stud3, petr);
    /*Stud2.Show();
    Stud3.Show();
    Stud1.Show();*/

///!!!!!!!!!!!!

}











int main(){
    List <Student> Stud1, Stud2, Stud3, Stud4, Stud5, Stud6;
    List <Professors> Prof1, Prof2, Prof3, Prof4;
    List <Functions> Func;
    Functions f1, f2, f3, f4;
    Professors mrX;
    Student petr;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int pop, i;

    string ppp;
    cout << "Что вы хотите сделать?\n1-Работать со списками\n2-Провести тест\n";
    cout << "Введите цифру:";
    cin >> pop;cin.get();+
    if (pop == 2){
        Test_Ready_List();
        Test_Sort();
        Test_Concat();
        Test_Search();
        Test_Division();
    }else if (pop == 1){
        system("cls");
        cout << "С какими списками вы хотите работать?\n1-Студенты\n2-Преподаватели\n";
        cout << "Введите цифру:";
        cin >> pop;cin.get();
        if (pop == 1){
            system("cls");
            cout << "Сколько списков вы хотите создать?\n1-1 для выполнения основных манипуляций\n2-2 для проведения конкатенации\n";
            cout << "Введите цифру:";
            cin >> pop;cin.get();
            if (pop == 1){
                system("cls");
                cout << "Вы хотите создать список самостоятельно или использовать готовый?\n1 - Самостоятельно\n2 - Готовый\n";
                cout << "Введите цифру:";
                cin >> pop;cin.get();
                if (pop == 1){
                    system("cls");
                    int i;
                    cout<<"Укажите, сколько студентов вы хотите добавить:"<<endl;
                    cout << "Вводите в формате Фамилия Имя Отчество Группа" << endl;
                    cin>>i;cin.get();
                    while (i!=0){
                        cin >> petr;cin.get();
                        Stud1.Add(petr);
                        i--;
                    }
                }else{
                    Stud1.Ready_List("WorkList.txt");
                }
                system("cls");
                while (1){
                    cout << "Что вы хотите сделать со списком?" << endl;
                    cout << "1 - Показать\n2 - Поиск по списку\n3 - Поиск одногруппников\n4 - Сортировать\nЛюбое другое значение - Выход из программы\n";
                    cout << "Введите цифру:";
                    cin >> pop;cin.get();
                    if (pop == 1){
                        Stud1.Show();
                    }else if (pop == 2){
                        cout << "Введите фамилию студента, которого вы хотите найти.\n";
                        cout << "->:";
                        cin >> ppp;
                        petr.surname = ppp;
                        Stud1.Search(petr);
                    }else if (pop == 3){
                        cout << "Введите группу, студентов которой вы хотите найти:";
                        cin >> ppp;
                        petr.group = ppp;
                        Stud1.Division(Stud2, Stud3, petr);
                    }else if (pop == 4){
                        Stud1.Sort();
                    }else{
                        exit(0);
                    }
                }
            }else{
                system("cls");
                cout << "Списки будут автоматически считаны из внешних файлов..."<<endl << endl;
                cout << "Первый список считан из ForTestConcat1.txt" << endl;
                Stud4.Ready_List("ForTestConcat1.txt");
                Stud4.Show();
                cout<<"Второй список считан из ForTestConcat2.txt" << endl;
                Stud5.Ready_List("ForTestConcat2.txt");
                Stud5.Show();

                cout << "После нажатия клавиши вы увидите готовый список."<<endl;
                system("pause");
                Stud4.Concat(Stud5);
                Stud4.Show();
            }
        }else if (pop == 2){
            system("cls");
            cout << "Сколько списков вы хотите создать?\n1-1 для выполнения основных манипуляций\n2-2 для проведения конкатенации\n";
            cout << "Введите цифру:";
            cin >> pop;cin.get();
            if (pop == 1){
                system("cls");
                cout << "Вы хотите создать список самостоятельно или использовать готовый?\n1 - Самостоятельно\n2 - Готовый\n";
                cout << "Введите цифру:";
                cin >> pop;cin.get();
                if (pop == 1){
                    system("cls");
                    int i;
                    cout<<"Укажите, сколько преподавателей вы хотите добавить:"<<endl;
                    cin>>i;cin.get();
                    cout << "Вводите в формате Фамилия Имя Отчество Предмет" << endl;/////////////////////////////////////////////////////////////////////////////////////
                    while (i!=0){
                        cin >> mrX;cin.get();
                        Prof1.Add(mrX);
                        i--;
                    }
                }else{
                    Prof1.Ready_List("ProfList1.txt");
                }
                system("cls");
                while (1){
                    cout << "Что вы хотите сделать со списком?" << endl;
                    cout << "1 - Показать\n2 - Поиск по списку\n3 - Поиск коллег\n4 - Сортировать\nЛюбое другое значение - Выход из программы\n";
                    cout << "Введите цифру:";
                    cin >> pop;cin.get();
                    if (pop == 1){
                        Prof1.Show();
                    }else if (pop == 2){
                        cout << "Введите фамилию преподавателя, которого вы хотите найти.\n";
                        cout << "->:";
                        cin >> ppp;
                        mrX.surname = ppp;
                        Prof1.Search(mrX);
                    }else if (pop == 3){
                        cout << "Введите предмет, преподавателей которого вы хотите найти:";
                        cin >> ppp;
                        mrX.subject = ppp;
                        Prof1.Division(Prof2, Prof3, mrX);
                    }else if (pop == 4){
                        Prof1.Sort();
                    }else{
                        exit(0);
                    }
                }
            }else{
                system("cls");
                cout << "Списки будут автоматически считаны из внешних файлов..."<<endl << endl;
                cout << "Первый список считан из ProfList1.txt" << endl;
                Prof3.Ready_List("ProfList1.txt");
                Prof3.Show();
                cout<<"Второй список считан из ProfList2.txt" << endl;
                Prof4.Ready_List("ProfList2.txt");
                Prof4.Show();

                cout << "После нажатия клавиши вы увидите готовый список."<<endl;
                system("pause");
                Prof3.Concat(Prof4);
                Prof3.Show();
            }
    }else{
        cout << "НЕВЕРНЫЙ ВВОД!" << endl;
    }
    ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/*
    int i;
    cout<<"Укажите
    , сколько студентов вы хотите добавить:";
    cin>>i;cin.get();
    while (i!=0){
        cin >> petr;
        Stud.Add(petr);
        i--;
    }
    cout<<"\n\n";
    Stud.Show();

    cout<<"Укажите, сколько студентов вы хотите добавить:";
    cin>>i;cin.get();
    while (i!=0){
        cin >> petr;
        Stud2.Add(petr);
        i-petr.name = "Азамат";
    petr.surname = "";
    petr.group = "";
    petr.patronymic = " ";
    Stud2.Add(petr);-;
    }
    cout<<"\n\n";
    Stud2.Show();
    Stud.Concatination(Stud2);
    Stud.Show();
    cout << endl;


petr.name = "Азамат";
    petr.surname = "";
    petr.group = "";
    petr.patronymic = " ";
    Stud2.Add(petr);
    Stud.Ready_List("WorkList.txt");
    Stud.Show();
    Stud.Division(Stud3, Stud4);
    //Stud.Search();

    cout << "\n\n";

    Prof.Ready_List("WorkList2.txt");
    Prof.Show();
    Prof.Search();
    Stud2.Ready_List("WorkList.txt");
    Stud2.Show();

    Stud.Sort();
    Stud.Show();
    Prof.Division(Prof1, Prof2);*/

    /*
    f1.Name = "Извлечение корня";
    f1.func = squareFoo;
    f2.Name = "Возведение в степень";
    f2.func = powFoo;
    f3.Name = "Обрезание дробной части";
    f3.func = truncFoo;
    f4.Name = "Экспонента";
    f4.func = expFoo;



    Func.Add(f1);
    Func.Add(f2);
    Func.Add(f3);
    Func.Add(f4);
    Func.Show();
    Func.Head->element.ToDo();
    Func.Head->Next->element.ToDo();*/

    /*Test_Ready_List();
    Test_Sort();
    Test_Search();
    Test_Division();*/


    return 0;
}
}

