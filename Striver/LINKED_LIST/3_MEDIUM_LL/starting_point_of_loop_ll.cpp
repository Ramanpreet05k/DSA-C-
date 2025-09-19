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

Node* startingpointofloop(Node* head){
    map<Node* , int> mpp;
    Node* temp = head;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}



Node* startingpointbytortoisemethod(Node* head){
    if(head== NULL || head->next == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast = fast->next->next;
         if(fast == slow){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
         }
        
    }
    return NULL;

}

int main(){
    vector<int> arr1 = {1,2,3,4};
    Node* head = convertarr2ll(arr1);
      head->next->next->next->next = head->next; 
      Node* loop = startingpointbytortoisemethod(head);
      cout<<loop->data;

    

    
    
    
    
}