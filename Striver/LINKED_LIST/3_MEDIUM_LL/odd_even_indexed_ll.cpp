#include<iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next= next1;
    }

    public:
    Node(int data1){
        data=data1;
        next = nullptr;
    }
};

Node* convertarrtoll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    int n = arr.size();
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node* oddevenindexedll(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    vector<int> arr;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);

   temp = head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    int i=0;
    temp = head;
    while(temp!=NULL){
        temp->data = arr[i];
        i++;
        temp= temp->next;
    }
    return head;
}

Node* oddevenindexingwithswapping(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenhead = head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next->next;
    } 
    odd->next = evenhead;
    return head;
}

int main(){
vector<int> arr = {1,3,5,2,4,6};
Node* head = convertarrtoll(arr);
print(head);
cout<<endl;
Node* newlist = oddevenindexedll(head);
print(newlist);
}