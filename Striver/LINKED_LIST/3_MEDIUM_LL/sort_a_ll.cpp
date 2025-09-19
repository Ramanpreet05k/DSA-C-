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

Node* sortll(Node* head){
    if(head == NULL || head->next==NULL){
        return head;
    }
    Node* temp = head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    int i=0;
    
    temp = head;
    while(temp!=NULL){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
}

Node* findmiddle(Node* head){
    Node* slow = head;
    Node* fast =head;
    while(fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}

Node* mergesortinll(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* middle = findmiddle(head);
    Node* lefthead = head;
    Node* righthead = middle->next;
    middle->next = NULL;
    lefthead= mergesortinll(lefthead);
    righthead = mergesortinll(righthead);

}




int main(){
    vector<int> arr  ={2,3,1,5,6,5,7};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* sortl = sortll(head);
    print(sortl);
    
}