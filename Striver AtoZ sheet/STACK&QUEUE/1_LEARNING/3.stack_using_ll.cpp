#include<iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data= data1;
        next= next1;
    }

    public:
    Node(int data1){
        data=data1;
        next = nullptr;
    }
};

struct nodestack{
    Node *top;
    int size;
    nodestack(){
        top=NULL;
        size=0;
    }
    void stackpush(int val){
        Node* temp = new Node(val);
        temp->next=top;
        top=temp;
        size=size+1;
    }

    void stackpop(){
        Node* temp = top;
        top=top->next;
        delete temp;
        size=size-1;

    }
    int topval(){
        return top->data;
    }
    int currsize(){
         return size;
    }
};

int main(){
    nodestack s;
  s.stackpush(10);
  s.stackpush(30);
  s.stackpush(50);
 s.stackpop();
  cout << "Stack size: " << s.currsize() << "\n";
  return 0;
}