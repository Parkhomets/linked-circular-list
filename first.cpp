#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
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
    void Show();            //show all items
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

void List:: Add(){//with each addition, the size of the list increases
    string Name;
    size++;
    getline(cin, Name);
    //cin>>Name;               //Enter a new element in a temporary variable
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

void List :: Show(){    //method of displaying list items
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
    ifstream inFile1("WorkList.txt",ios::in);
    int iter = 0;
    string s;
    while (inFile1.peek() != EOF)
    {
        getline(inFile1, s);
        iter++;
    }
    inFile1.close();
    ifstream inFile("Worklist.txt",ios::in);
    const int len = 30;
    const char ch = '\n';
    char mass[len][iter];
    if(!inFile) cout<<"incorrect input";
    else{
        for(int r=0; r<iter;r++)
        {
            inFile.getline(mass[r],len-1,ch);
            size++;
            Node *temp = new Node;
            temp->Next = Head;
            temp->Name = mass[r];
            if (Head!=NULL){
                Tail->Next = temp;
                Tail = temp;
            }
            else{
                Head = Tail = temp;
            }
        }
    }

    inFile.close();
}

int main(){
    List lst;
    int i;

    cout<<"How many items will contain your list? Enter a number:";
    cin>>i;cin.get();                    //The keyboard buffer is empty symbol, which I removed using cin.get()
    while (i!=0){
        lst.Add();
        i--;
    }
    cout<<"\n\n";
    lst.Show();
    /*lst.Ready_List();
    lst.Show();*/
    return 0;
}

