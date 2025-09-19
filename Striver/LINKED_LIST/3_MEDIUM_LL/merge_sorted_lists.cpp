
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


void sortArray(vector<int> &arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

Node* mergesortedll(Node* head1 , Node* head2){
    Node* temp = head1;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    temp = head2;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    int length = arr.size();
    sortArray(arr, length);
    Node* res = convertarr2ll(arr);
    return res;
   
}

Node* mergesortedllbytwopointer(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1!=NULL && t2!=NULL){
         if(t1->data<t2->data){
            temp->next = t1;
            temp=t1;
            t1=t1->next;
           
         }
         else{
            temp->next = t2;
            temp=t2;
            t2 =t2->next;
         }

    }
    if (t1) temp->next=t1;
    else temp->next = t2;

    return dummy->next;
}



int main(){
    vector<int> arr1  ={2,4,8,10};;
    Node* head1 =convertarr2ll(arr1);
    print(head1);
    cout<<endl;
    vector<int> arr2 = {1,3,3,6,11,14};
   Node* head2 = convertarr2ll(arr2);
   Node* res = mergesortedll(head1,head2);
   print(res);
   cout<<endl;
   Node* res2 = mergesortedllbytwopointer(head1, head2);
   print(res2);
    
}