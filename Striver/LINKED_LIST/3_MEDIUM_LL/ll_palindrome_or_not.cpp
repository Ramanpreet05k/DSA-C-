#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
// Add more as needed

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

bool checkpalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* reverselinkedlist(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* newhead = reverselinkedlist(head->next);
    Node* front = head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}

bool checkpalindromewithoutstack(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newhead = reverselinkedlist(slow->next);
    Node* first = head;
    Node* second = newhead;
    while(second!=NULL){
        if(first->data != second->data){
            reverselinkedlist(newhead);
            return false;
        }
        first = first->next;
        second=second->next;
    }
    reverselinkedlist(newhead);
    return true;
}

int main(){
    vector<int> arr = {1,2,3,2,1};
    Node* head = convertarrtoDLL(arr);
    print(head);
    cout<<endl;
    bool result = checkpalindromewithoutstack(head);
cout<<result;
}


