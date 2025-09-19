#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
// Add more as needed

#include<vector>
#include<stack>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarrtoDLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int len = arr.size();
    for(int i=1;i<len;i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deleteoccurances(Node* head, int key){
   Node* temp = head;
   while(temp!=NULL){
    if(temp->data == key){
        if(temp==head){
            head = head->next;   
        }
        Node* nextnode = temp->next;
        Node* prevnode = temp->back;

        if(nextnode) nextnode->back = prevnode;
        if(prevnode) prevnode->next = nextnode;

       delete temp;
        temp = nextnode;
    }
    else{
        temp=temp->next;
    }
   }
   return head;
}



int main(){
    vector<int> arr = {10,4,10,10,5,6,10};
    Node* head = convertarrtoDLL(arr);
    print(head);
    cout<<endl;
    Node* newnode = deleteoccurances(head , 10);
    print(newnode);
    
}
