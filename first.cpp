#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>
#include <typeinfo>
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
    void Search();
    void Concatination(List<T> lst);
    void Sort();
    void Division(List<T> lst, List<T> lstt);
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
void List <T> :: Division(List <T> lst, List <T> lstt){
    T petr;
    Node *tempHead = Head;
    cout << "Найдите одногруппников/коллег (например, Петрова Петра Петровича Б16101)" << endl;
    cout << "Список будет разделен на одногруппников/коллег и остальных людей"<<endl;
    cin >> petr;
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
void List<T>::Search(){
    T petr;
    Node *tempHead = Head;
    int var = 0;
    cin >> petr;
    Node *temp = this->Head;
    while (var++ < size)
    {
        if (temp->element == petr)
            {
                cout << var << " ";
                cout << petr;
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
        }
    inFile.close();
}
template <typename T>
void List <T> :: Sort(){
    Node *tempHead1 = Head;
    Node *tempHead2 = tempHead1->Next;
    Node *tempHeadVar = new Node;
    int var = this->size-1, var1 = this->size-1;
    while (var1 != 0)
    {
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

int main(){
    List <Student> Stud;
    List <Student> Stud2, Stud3, Stud4;
    List <Professors> Prof, Prof1, Prof2;

    Professors mrX;
    Student petr;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
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
        i--;
    }
    cout<<"\n\n";
    Stud2.Show();
    Stud.Concatination(Stud2);
    Stud.Show();
    cout << endl;*/



    Stud.Ready_List("WorkList.txt");
    Stud.Show();
    Stud.Division(Stud3, Stud4);
    //Stud.Search();

    cout << "\n\n";

    Prof.Ready_List("WorkList2.txt");
    Prof.Show();
    /*Prof.Search();
    Stud2.Ready_List("WorkList.txt");
    Stud2.Show();*/

    /*Stud.Sort();
    Stud.Show();*/
    Prof.Division(Prof1, Prof2);





    return 0;
}

