#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>

using namespace std;
/*
struct Node{
    string Name;
    string Difference;
    Node *Next;
};*/

template <typename T>
class List{
    /*struct Node{
        T element;
        Node *Next;
    };*/
    //Node *Head, *Tail;   //the first and last elements
    //int size;            //the number of elements in the list
public:
    List():Head(NULL),Tail(NULL),size(0){}; //initialize the elements to 0 using the designer
    ~List();    //destructor to free memory
    struct Node{
        T element;
        Node *Next;
    };
    Node *Head, *Tail;
    void Add(T element);                     //method to add item
    void Show();            //show all items
    void Ready_List();
    void SearchName();
    void SearchDif();
    int size;                       //the number of elements in the list
};

class Student{
    public:
    string surname;
    string name;
    string patronymic;
    string group;
        /*Student(string str1, string str2, string str3, string str4){
            surname = str1;
            name =str2;
            patronymic =str3;
            group = str4;
        }*/
        void Show();
};
class Professors{
    public:
    string surname;
    string name;
    string patronymic;
    string subject;

        void Show();
};

template <typename T>
List <T> :: ~List(){                    //delete class
    while (size!=0){
        Node *temp = Head->Next;    //select the active item
        delete Head;                //delete the active item
        Head = temp;                //displace the pointer
        size--;
    }
}

template <typename T>
void List <T> :: Add(T element){//with each addition, the size of the list increases
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

/*void Fusion(){
    Node *res = concatenate()

}*/
void Student :: Show(){
    cout<<surname<<" "<<name<<" "<<patronymic<<" "<<group<<endl;
}
void Professors :: Show(){
    cout<<surname<<" "<<name<<" "<<patronymic<<" "<<subject<<endl;
}

template <typename T>
void List <T> :: Show(){    //method of displaying list items
    Node *tempHead = Head;      //put the pointer to the first element
    int temp = size;//set up a temporary variable for convenience of output
    int counter = 1;
    while (temp!=0){
        tempHead->element.Show();
        tempHead = tempHead->Next; //put the pointer to the next element
        temp--; counter++;        //reduce the counter
    }
    // cout<<'\n';
}
/*
void List::SearchName(){
    Node *tempHead = Head;
    int var = size;
    string usename;
    cout<<"\nВведите ФИО:"; getline(cin,usename);
    int volume = usename.size();
    int counter = 1;
    int i = 0;

    while (var!=0)
        {
            if (usename == tempHead->Name)
            {
                cout<<counter<<":"<<tempHead->Name<<tempHead->Difference<<endl;
                tempHead = tempHead->Next;
                i++;
            }
            else
            tempHead = tempHead->Next;
            var--; counter++;
        }
    if (i == 0)
        cout<<"Doesn't found!";

}
void List :: SearchDif(){
Node *tempHead = Head;
    int var = size;
    string usename;
    cout<<"\nВведите параметр:"; getline(cin,usename);
    usename = " " + usename;

    int volume = usename.size();
    int counter = 1;
    int i = 0;

    while (var!=0)
        {
            if (usename == tempHead->Difference)
            {
                cout<<counter<<":"<<tempHead->Name<<tempHead->Difference<<endl;
                tempHead = tempHead->Next;
                i++;
            }
            else
            tempHead = tempHead->Next;
            var--; counter++;
        }
    if (i == 0)
        cout<<"Doesn't found!";
}

void List::Ready_List(){
    string line1, line2;
    ifstream inFile("WorkList.txt",ios::in);
    if (inFile.is_open())
        while (!inFile.eof())
        {
            getline(inFile,line1,';');
            getline(inFile,line2,'\n');
            size++;
            Node *temp = new Node;
            temp->Next = Head;
            temp->Name = line1;
            temp->Difference = line2;
            if (Head!=NULL){
                Tail->Next = temp;
                Tail = temp;
            }
            else{
                Head = Tail = temp;
            }
        }
    inFile.close();
}
*/

int main(){
    List <Student> Stud;
    //List lst;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i;

    cout<<"How many items will contain your list? Enter a number:";
    cin>>i;cin.get();    //The keyboard buffer is empty symbol, which I removed using cin.get()
    while (i!=0){


        //Stud.Add(Student{});
        getline(cin, Stud.Head->element.name);
        getline(cin, Stud.Head->element.patronymic);
        getline(cin, Stud.Head->element.surname);
        getline(cin, Stud.Head->element.group);

        i--;
    }
    cout<<"\n\n";
    Stud.Show();
    //lst.Ready_List();
    //lst.Show();
    //lst.SearchName();
    //lst.SearchDif();

    return 0;
}

