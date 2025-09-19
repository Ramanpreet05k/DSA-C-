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

Node* middleofLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    temp = head;
     int midnode = (cnt/2)+1;
     while(temp!=NULL){
        midnode= midnode-1;
        if(midnode==0){
            break;
        }
        temp=temp->next;
     }
     return temp;
}


Node* tortoiseandhars(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr  ={1,2,3,4,5};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* midnode = middleofLL(head);
    print(midnode);
    cout<<endl;
    Node* midnode2 = tortoiseandhars(head);
    print(midnode2);
    
}