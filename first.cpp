#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int x;
    Node *Next;
};

class List{
    Node *Head, *Tail; //первый и последний элементы
    int size;         //число элементов в списке
    public:
      List():Head(NULL),Tail(NULL),size(0){};   //иниц элементов в 0 с помощью конструктора
      ~List();      //деструктор дл€ освобождени€ пам€ти
      void Add(int x); //добавление нового элемента
      void Show(int size);  //отображение элементов списка
      int Count();          //подсчет элементов в списке
};
List::~List(){
    while (size!=0){
        Node *temp=Head->Next;
        delete Head; //удаление активного элемента
        Head = temp; //смена адреса начала на адрес следующего элемента
        size--;
    }
}

int List :: Count(){
    return size;
}
void List :: Add(int x){
    size++;      //при каждом добавлении размер списка увеличиваетс€
    Node *temp = new Node; //выделение пам€ти дл€ нового элемента
    temp->Next = Head; //заммыкание контура
    temp->x = x; //записываем в выделенную €чейку пам€ти определенное значение значение
    if (Head!=NULL){  //если список не пустой
        Tail->Next = temp; //записываем данные в самый конец после посленего элемента
        Tail = temp; //мещаем наш указатель хвоста на последний элемент
    }
    else{  //если список пустой
        Head = Tail = temp;
    }
}
void List :: Show(int size){  //выводим элементы списка
    Node *tempHead = Head; //указатель показывает на начало списка
    int temp = size;    //временна€ переменна€ равна€ числу элементов в списке
    while (temp!=0){
        cout<<tempHead->x<<" ";   //выводим очередной элемент на экран
        tempHead = tempHead->Next;  //указываем на следующий элемент
        temp--; //элемент считан, значит, осталось на один элемент меньше
    }
}
int main(){
    List lst;
    lst.Add(100);
    lst.Add(200);
    lst.Add(300);
    lst.Show(lst.Count()); //здесь € вывожу весь список на экран
return 0;
}
