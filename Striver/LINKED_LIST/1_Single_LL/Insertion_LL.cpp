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

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* convertarr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    int len = arr.size();

    for(int i=1;i<len;i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* Inserttohead(Node* head , int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node* Inserttotail(Node* head , int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newnode = new Node(val);
    temp->next = newnode;

    return head;
}

Node* Inserttokthelement(Node* head , int val , int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }

    if (k==1){
        Node* temp = new Node(val,head);
        return temp;
    }

    int cnt=0;
    Node* temp = head;

    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            temp->next= newnode;
            break;
        }
        temp=temp->next;
    }

    return head;

}


Node* insertbeforevaluex(Node* head , int val, int x){
    if(head == NULL){
        return NULL;
    }
    if(head->data == x){
        return new Node(val, head);
       
    }

    Node* temp = head;

    while(temp->next!=NULL){
        if(temp->next->data==x){
            Node* newnode = new Node(val,temp->next);
            temp->next = newnode;
            break;
        }

        temp=temp->next;
        
    }

    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head =convertarr2ll(arr);
    cout<<endl;
    print(head);

    head = Inserttohead(head , 100);
    cout<<endl;
    print(head);

    head = Inserttotail(head , 200);
    cout<<endl;
    print(head);

    head = Inserttokthelement(head , 20, 11);
    cout<<endl;
    print(head);

    head = insertbeforevaluex(head, 1900,20);
    cout<<endl;
    print(head);   
}