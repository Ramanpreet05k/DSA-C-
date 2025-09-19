#include<iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

#include<vector>
#include <list>
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


list<pair<int, int>>  pairwithsum(Node* head, int sum){
    Node* temp1 = head;
   list<pair<int, int>> mylist;  
    while(temp1!=NULL){
        Node* temp2 = temp1->next;
        while(temp2!=NULL){
            if(temp1->data + temp2->data == sum){
                mylist.push_back({temp1->data, temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }

    return mylist;

}

void printPairs(list<pair<int, int>> pairs) {
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
}

Node* findtail(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
}
Node* temp = head;
while(temp->next!=NULL){
    temp=temp->next;
}
return temp;
}

list<pair<int,int>> pairwithsumbytwopointer(Node* head , int sum){
    Node* left = head;
    Node* right = findtail(head);
    list<pair<int,int>> mylist;
    while(left->data<right->data){
        if(left->data+right->data==sum){
            mylist.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }

        else if(left->data+right->data>sum){
            right=right->back;
        }
        else{
            left = left->next;
        }
    
    }
    return mylist;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertarrtoDLL(arr);
    print(head);
    cout<<endl;
   printPairs(pairwithsumbytwopointer(head,5));
    
}
