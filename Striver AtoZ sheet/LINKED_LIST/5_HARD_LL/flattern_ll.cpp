#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
// Add more as needed

#include<vector>
#include<algorithm>
using namespace std;


struct Node{
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(int data1, Node* next1, Node* child1){
        data = data1;
        next = next1;
        child = child1;

    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};



void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->child;
       
    }
     cout<<endl;
}


Node* convertarr2flatternll(vector<int> &arr){
   if(arr.size()==0) return NULL;
   Node* head = new Node(arr[0]);
   Node* temp = head;
   int length = arr.size();
   for(int i=1;i<length;i++){
    Node* newnode = new Node(arr[i]);
    temp->child = newnode;
    temp=temp->child;
   }
   return head;
}

Node* flatternll(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp!=NULL){
        Node* t2 = temp;
        while(t2!=NULL){
            arr.push_back(t2->data);
            t2=t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    Node* result = convertarr2flatternll(arr);
    return result;
}


Node* flatternllwithtwopointer(Node* list1, Node* list2){
    Node* dummynode = new Node(-1);
    Node* res = dummynode;
    while(list1!=NULL && list2!=NULL){
        if (list1->data<list2->data){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }
    if(list1) res->child = list1;
    else res->child = list2;

    return dummynode->child;
}

Node* flattern(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mergehead= flattern(head->next);
    return flatternllwithtwopointer(head, mergehead);
}


int main(){
      Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->child = new Node(4);
    head->next->child->child = new Node(5);
    head->next->child->child->child = new Node(6);

    head->next->next->child = new Node(7);
    head->next->next->child->child = new Node(8);

    // Flatten
    Node* flat = flattern(head);

    // Print flattened list
    cout << "Flattened linked list (via child pointers):" << endl;
    print(flat);

    
   
    
}