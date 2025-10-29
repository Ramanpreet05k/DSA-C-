#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
// Add more as needed

#include <vector>
using namespace std;

struct Node
{
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArr2ll(vector<int> &arr){
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
        head = head->next;
    }
    cout<<endl;
}

Node* removehead(Node* head){
    if(head==NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node* removekthelement(Node* head, int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;

    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    return head;

}


Node* removeval(Node* head, int val){
    if (head==NULL){
        return head;
    }

    if(head->data==val){
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp!=NULL){
        if(temp->data==val){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;

    }
    return head;
}

int main(){
    vector<int> arr={3,4,6,7,9,8,6,2,5};

    Node* head = ConvertArr2ll(arr);
   
    print(head);

    head = removehead(head);
    print(head);

    head = removetail(head);
    print(head);

    head = removekthelement(head, 3);
    print(head);

    head = removeval(head,4);
    print(head);
}