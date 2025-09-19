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

Node* addtwoll(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummynode = new Node(-1);
    Node* curr = dummynode;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        int sum = carry;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;
        Node* newnode = new Node(sum%10);
        carry = sum/10;

        curr->next = newnode;
        curr = curr->next;

        if(t1) t1= t1->next;
        if(t2) t2= t2->next;
    }
    if(carry){
        Node* newnode = new Node(carry);
        curr->next = newnode;
        curr = curr->next;
    }
    return dummynode->next;
}

int main(){
    vector<int> arr1={3,5};
    Node* head1 = convertarrtoll(arr1);
    cout<<endl;
    print(head1);
    vector<int> arr2={4,5,9,9};
    Node* head2 = convertarrtoll(arr2);
    cout<<endl;
    print(head2);

    Node* sum = addtwoll(head1, head2);
    cout<<endl;
    print(sum);



}