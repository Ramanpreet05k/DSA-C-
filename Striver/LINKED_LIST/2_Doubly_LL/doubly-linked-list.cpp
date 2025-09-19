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
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};


Node* convertarr2dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int len = arr.size();
    for(int i=1;i<len;i++){
        Node* temp= new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev = temp;
    }

    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    Node* head = convertarr2dll(arr);
    print(head);
}

