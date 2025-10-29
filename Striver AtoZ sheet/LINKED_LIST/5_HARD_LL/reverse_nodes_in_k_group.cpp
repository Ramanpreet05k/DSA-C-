#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <stack>
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

Node *findkthnode(Node *head, int k)
{
    k-=1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (k == 0)
        {
            return temp;
        }
        k--;
        temp=temp->next;
    }
    return NULL;
}

Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    Node* front = head->next;
    while(temp!=NULL){
        front = temp->next;
        temp->next = prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node *reversekgroup(Node *head, int k)
{
    Node *temp = head;
   
    Node *prevnode = NULL;
    while (temp != NULL)
    {
        Node *knode = findkthnode(temp, k);
        if (knode == NULL)
        {
          if(prevnode)  prevnode->next = temp;
            break;
        }
        Node* nextnode = knode->next;
        knode->next = NULL;
       reverse(temp);
        if (temp == head)
        {
            head = knode;
        }
        else
        {
            prevnode->next = knode;
        }
        prevnode = temp;
        temp = nextnode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node *head = convertarr2ll(arr);
    print(head);
    cout << endl;
    Node* newnode = reversekgroup(head , 3);
    print(newnode);
}
