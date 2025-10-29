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


Node* rotatell(Node* head, int k){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* tail = head;
    int length = 1;
    while(tail->next!=NULL){
        length++;
        tail = tail->next;
    }

   k=k%length;
   if(k==0) return head;

    Node* temp = head;
    int cnt = length - (k%length);
    while(temp!=NULL){
        cnt--;
        if(cnt==0){
            break;
        }
        
        temp=temp->next;
    }

    Node* newhead = temp->next;
    temp->next = NULL;
    tail->next=head;
return newhead;
}

int main(){
    vector<int> arr  ={1,2,3,4,5};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* rotatdnode = rotatell(head,2);
    print(rotatdnode);
    
}