#include<iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>

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

Node* intersectionpointbymapping(Node* head1, Node* head2){
    map<Node*,int> mpp;
    Node* temp = head1;
    while(temp!=NULL){
        mpp[temp]=1;
        temp = temp->next;
    }
    temp = head2;
    while(temp!=NULL){
        if(mpp.find(temp)== mpp.end()){
            return temp;
        }
        temp=temp->next;

    }
    return NULL;
}

Node* collisionpoint(Node* head1 , Node* head2, int d){
    while(d){
        d--;
        head2= head2->next;
    }
    while(head1!=NULL){
        head1=head1->next;
        head2=head2->next;
    }
    return head1;

}

Node* intersectingpoint(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    int n1 = 0;
    int n2 = 0;
    while(t1!=NULL){
        n1++;
        t1=t1->next;
    }
    while(t2!=NULL){
        n2++;
        t2=t2->next;
    }
    if(n1>n2) return collisionpoint(head2, head1, n1-n2);
    else return collisionpoint(head1, head2, n2-n1);
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    Node* head1 = convertarrtoDLL(arr1);
    print(head1);
    cout<<endl;
    vector<int> arr2 = {6,7,3,4,5};
    Node* head2 = convertarrtoDLL(arr2);
    print(head2);
    cout<<endl;
    Node* intersect = intersectingpoint(head1, head2);
    cout<<intersect;
   
   
}
