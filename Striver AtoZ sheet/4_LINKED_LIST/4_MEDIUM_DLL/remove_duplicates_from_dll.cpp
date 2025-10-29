#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include<vector>
#include <list>
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


list<pair<int, int>>  pairwithsum(Node* head, int sum){
    Node* temp1 = head;
   list<pair<int, int>> mylist;  
    while(temp1!=NULL){
        Node* temp2 = temp1->next;
        while(temp2!=NULL){
            if(temp1->data + temp2->data == sum){
                mylist.push_back({temp1->data, temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }

    return mylist;

}


Node* removeduplicates(Node* head){
    if (head==NULL && head->next==NULL){
        return head;
    }
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        Node* newnode = temp->next;
        while(newnode!=NULL && newnode->data == temp->data){
            Node* duplicatenode = newnode;
            newnode=newnode->next;
            delete duplicatenode;
        }
        temp->next = newnode;
        if(newnode) newnode->back = temp;

        temp=temp->next;
    }

    return head;

}


int main(){
    vector<int> arr = {1 ,1,1,2,2,3,3,4,5,5};
    Node* head = convertarrtoDLL(arr);
    print(head);
    cout<<endl;
    Node* newhead = removeduplicates(head);
    print(newhead);
  
    
}
