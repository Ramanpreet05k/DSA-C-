#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarrtoDLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int len = arr.size();
    for(int i=1;i<len;i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* reversedllbyswapping(Node* head){
    if( head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    Node* temp =head;
    Node* current = NULL;
    while(temp!=NULL){
        current = temp->back;
        temp->back = temp->next;
        temp->next = current;
        temp = temp->back;
    }
    if (current != NULL) {
        head = current->back;
    }
    return head;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertarrtoDLL(arr);
    print(head);
    /*Node* temp = head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    cout<<endl;
    print(head);*/

    Node* rev= reversedllbyswapping(head);

    cout<<endl;
    print(rev);
}
