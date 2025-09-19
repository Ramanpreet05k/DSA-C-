#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
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

Node* removenthnode(Node* head, int n){
    int cnt = 0;
    Node* temp = head; 
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt==n){
        Node* newhead = head->next;
        free(head);
        return newhead;
    }
    int res = cnt-n;
    temp= head;
    while(temp!=NULL){
        res--;
        if(res==0){
            break;
        }
        temp=temp->next;
    }

    Node* delnode = temp->next;
    temp->next = temp->next->next;
    free(delnode);
    return head;
}

Node* removenthnodeinonetraverse(Node* head, int n){
    Node* fast = head;
    for(int i=0;i<n;i++){
        fast= fast->next;
    }

    if(fast==NULL){
        return head->next;
    }
    Node* slow = head;
    while(fast->next !=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* delnode = slow->next;
    slow->next = slow->next->next;
    free(delnode);
    return head;

}



int main(){
    vector<int> arr  ={1,2,3,4,5};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* removenode = removenthnode(head , 2);
    print(removenode);
    cout<<endl;
    Node* newnode1 = removenthnodeinonetraverse(head,2);
    print(newnode1);
    cout<<endl;
   

}