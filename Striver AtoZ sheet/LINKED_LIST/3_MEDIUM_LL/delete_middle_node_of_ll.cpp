#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
// Add more as needed

#include<vector>
using namespace std;


struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertarr2ll(vector<int> &arr){
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
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}


Node* deletemiddlenode(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp = head;
    int length =0;

    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    int midnode= length/2;
    temp = head;
    while(temp!=NULL){
        midnode=midnode-1;
        if(midnode==0){
            break;
        }
        temp=temp->next;
    }
    Node* middle = temp->next;
    temp->next = temp->next->next;
    delete middle;
    
    return head;
}

Node* deletemiddlenodebytortoisemethod(Node* head){
     if(head==NULL || head->next==NULL){
        return head;
    }
    Node* slow= head;
    Node* fast = head;
    fast = fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = slow->next->next;
    delete mid;
    return head;
}


int main(){
    vector<int> arr  ={1,2,3,4,5};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* midnode = deletemiddlenodebytortoisemethod(head);
    print(midnode);
    
    
}