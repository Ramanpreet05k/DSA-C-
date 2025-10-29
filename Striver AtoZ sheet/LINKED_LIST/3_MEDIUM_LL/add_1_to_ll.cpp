
#include <iostream>
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

Node* reversebyrecursion(Node* head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    Node* newhead = reversebyrecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}


Node* add1toll(Node* head){
    Node* revhead= reversebyrecursion(head);
    int carry = 1;
    Node* temp = revhead;
    while(temp!=NULL){
       int sum= carry + temp->data;
       temp->data = sum;
       if(sum<10){
        carry=0;
        break;
       }
      else{
         temp->data=0;
       carry=1;
      }
      temp = temp->next;
    }
    if(carry==1){
        Node* newnode = new Node(1);
        head = reversebyrecursion(revhead);
        newnode->next = head;
        return newnode;
    }
    head= reversebyrecursion(revhead);
    return head;
    
}

int helper(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry = helper(temp->next);
    temp->data = temp->data + carry;

    if(temp->data<10){
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* func(Node* head){
    int carry = helper(head);
    if(carry==1){
        Node* newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    return head;
}

int main(){
    vector<int> arr  ={9,9,9};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* newlist = func(head);
    print(newlist);
    
    
}