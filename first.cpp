#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int x;
    Node *Next;
};

class List{
    Node *Head, *Tail; //������ � ��������� ��������
    int size;         //����� ��������� � ������
    public:
      List():Head(NULL),Tail(NULL),size(0){};   //���� ��������� � 0 � ������� ������������
      ~List();      //���������� ��� ������������ ������
      void Add(int x); //���������� ������ ��������
      void Show(int size);  //����������� ��������� ������
      int Count();          //������� ��������� � ������
};
List::~List(){
    while (size!=0){
        Node *temp=Head->Next;
        delete Head; //�������� ��������� ��������
        Head = temp; //����� ������ ������ �� ����� ���������� ��������
        size--;
    }
}

int List :: Count(){
    return size;
}
void List :: Add(int x){
    size++;      //��� ������ ���������� ������ ������ �������������
    Node *temp = new Node; //��������� ������ ��� ������ ��������
    temp->Next = Head; //���������� �������
    temp->x = x; //���������� � ���������� ������ ������ ������������ �������� ��������
    if (Head!=NULL){  //���� ������ �� ������
        Tail->Next = temp; //���������� ������ � ����� ����� ����� ��������� ��������
        Tail = temp; //������ ��� ��������� ������ �� ��������� �������
    }
    else{  //���� ������ ������
        Head = Tail = temp;
    }
}
void List :: Show(int size){  //������� �������� ������
    Node *tempHead = Head; //��������� ���������� �� ������ ������
    int temp = size;    //��������� ���������� ������ ����� ��������� � ������
    while (temp!=0){
        cout<<tempHead->x<<" ";   //������� ��������� ������� �� �����
        tempHead = tempHead->Next;  //��������� �� ��������� �������
        temp--; //������� ������, ������, �������� �� ���� ������� ������
    }
}
int main(){
    List lst;
    lst.Add(100);
    lst.Add(200);
    lst.Add(300);
    lst.Show(lst.Count()); //����� � ������ ���� ������ �� �����
return 0;
}
