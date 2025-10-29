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

Node* reversell(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp= temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

Node* reversellwithoutstack(Node* head){
    if(head == NULL || head-> next == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev=NULL;
    Node* front = head->next;
    while(temp!=NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
        
    }
    return prev;
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


int main(){
    vector<int> arr  ={1,2,3,4,5};
    Node* head =convertarr2ll(arr);
    print(head);
    cout<<endl;
    /*Node* rev = reversell(head);
    print(rev);
    cout<<endl;*/
    Node* rev2 = reversellwithoutstack(head);
    print(rev2);
    cout<<endl;
    Node* revbyrec = reversebyrecursion(head);
    print(revbyrec);
    
}