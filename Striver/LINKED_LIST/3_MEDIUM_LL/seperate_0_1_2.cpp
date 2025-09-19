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

Node* seperate_0_1_2(Node* head){
    Node* temp = head;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    while(temp!=NULL){
        if(temp->data == 0) cnt0++;
        else if(temp->data==1) cnt1++;
        else cnt2++;
        temp= temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(cnt0){
             temp->data = 0;
             cnt0--;
        }
        else if(cnt1) {
            temp->data=1;
            cnt1--;
        }
        else {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

Node* seperatewithapproach2(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* zerohead = new Node(-1);
    Node* zero = zerohead;

    Node* onehead = new Node(-1);
    Node* one = onehead;

    Node* twohead = new Node(-1);
    Node* two = twohead;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (onehead->next)? onehead->next: twohead->next;
    one->next = twohead->next;
    two->next = NULL;
    Node* newhead = zerohead->next;
    delete(zerohead);
     delete(onehead);
      delete(twohead);
    return newhead;
}

int main(){
    vector<int> arr  ={1,0,1,2,2,0,2,2,1};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    Node* newnode= seperate_0_1_2(head);
    print(newnode);
    cout<<endl;
    Node* newnode1= seperatewithapproach2(head);
    print(newnode1);
}