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

Node* mergeksortedlists(vector<Node*> lists){
    vector<int> arr;
    int length = lists.size();
    for(int i=0;i<length;i++){
        Node* temp = lists[i];
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* result = convertarr2ll(arr);
    return result;

}


Node* mergetwolists(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    Node* temp1= head1;
    Node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp->next = temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }

    }
    if(temp1) temp->next = temp1;
    if(temp2) temp->next=temp2;

    return dummy->next;
}


Node* mergelists(vector<Node*> lists){
    Node* head = lists[0];
    int length = lists.size();
    for(int i=1;i<length;i++){
        head = mergetwolists(head , lists[i]);
    }

    return head;
}

Node* mergelistswithpq(vector<Node*> lists){
    priority_queue<pair<int,Node*>> pq;
    int size = lists.size();
    for(int i=0;i<size;i++){
        pq.push({lists[i]->data,lists[i]});
    }
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(!pq.empty()){
        pair<int,Node*> p = pq.top();
        temp->next = p.second;
        pq.pop();
        if(p.second->next){
            pq.push({p.second->next->data,p.second->next});
            temp=temp->next;
        }

    }
    return dummy->next;
}


    

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head =convertarr2ll(arr);
    cout<<endl;
    print(head);
    vector<int> arr2 = {1,1,3,7};
    Node* head2 = convertarr2ll(arr2);
    cout<<endl;
    print(head2);
    vector<int> arr3 = {1,5};
    Node* head3 = convertarr2ll(arr3);
    cout<<endl;
    print(head3);
    vector<Node*> lists;
    lists.push_back(head);
    lists.push_back(head2);
    lists.push_back(head3);
    Node* result = mergelistswithpq (lists);
    cout<<endl;
    print(result);


 
}