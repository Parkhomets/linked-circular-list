#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    string Name;
    Node *Next;
};

class List{
    Node *Head, *Tail;   //the first and last elements
    //int size;            //the number of elements in the list
public:
    List():Head(NULL),Tail(NULL),size(0){}; //initialize the elements to 0 using the designer
    ~List();                        //destructor to free memory
    void Add();                     //method to add item
    void Show(int size);            //show all items
    void Ready_List();
    //int Count();
    int size;                       //the number of elements in the list
};

List :: ~List(){                    //delete class
    while (size!=0){
        Node *temp = Head->Next;    //select the active item
        delete Head;                //delete the active item
        Head = temp;                //displace the pointer
        size--;
    }
}

/*
int List :: Count(){
    return size;
}
*/

void List:: Add(){
    string Name;
    size++;                     //with each addition, the size of the list increases
    cin >> Name;                //Enter a new element in a temporary variable
    Node *temp = new Node;      //allocate memory for the new list node
    temp->Next = Head;          //short circuit
    temp->Name = Name;          //the entry of a new element in the active node
    if (Head!=NULL){            //if list is not empty
        Tail->Next = temp;      //put the new node at the end
        Tail = temp;            //Do newly added node active
    }
    else{                       //if list is empty
        Head = Tail = temp;     //the new element becomes the beginning and end, and active, that is the only
    }
}

void List :: Show(int size){    //method of displaying list items
    Node *tempHead = Head;      //put the pointer to the first element
    int temp = size;            //set up a temporary variable for convenience of output
    int counter = 1;
    while (temp!=0){
        cout<<counter<<":";
        cout<<tempHead->Name<<"\n";
        tempHead = tempHead->Next; //put the pointer to the next element
        temp--; counter++;         //reduce the counter
    }
}

void List:: Ready_List(){ //here I will enter the reading list from external file


}

int main(){
    List lst;
    int i;
    cout<<"How many items will contain your list? Enter a number:";
    cin>>i;
    while (i!=0){
        lst.Add();
        i--;
    }
    cout<<"\n\n";
    lst.Show(lst.size);
    return 0;
}

