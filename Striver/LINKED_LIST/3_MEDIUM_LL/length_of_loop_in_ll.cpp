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

int lengthofloop(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    int timer = 1;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            int value = mpp[temp];
            return timer-value;
        }
        mpp[temp]= timer;
        timer++;
        temp=temp->next;
    }
return 0;
}

int findlength(Node* slow , Node* fast){
     int cnt = 1;
     fast=fast->next;
     while(fast!=slow){

        cnt++;
        fast = fast->next;
     }
     return cnt;
}

int lengthofloopbytortoisemethod(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findlength(slow,fast);
        }

    }
    return 0;
}

int main(){
    vector<int> arr1 = {1,2,3,4};
    Node* head = convertarrtoDLL(arr1);
      head->next->next->next->next = head->next; 
int length = lengthofloop(head);
cout<<length;

    
   
   
}
