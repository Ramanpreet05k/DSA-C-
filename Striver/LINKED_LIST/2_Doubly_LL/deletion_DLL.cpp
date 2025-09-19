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
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertarr2dll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    int len = arr.size();
    for (int i = 1; i < len; i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node *deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *deletetail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    tail->back = NULL;
    prev->next = NULL;

    return head;
}

Node *deletekthelement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == NULL && front == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (prev == NULL)
    {
        return deletehead(head);
    }
    else if (front == NULL)
    {
        return deletetail(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
    return head;
}

void deletenode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    // last node
    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = NULL;
    free(temp);
}

Node *insertbeforehead(Node *head, int val)
{
    Node *newhead = new Node(val, head, nullptr);
    head->back = newhead;

    return newhead;
}

Node *insertbeforetail(Node *head, int val)
{

    if (head->next == NULL)
    {
        return insertbeforehead(head, val);
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newnode = new Node(val, tail, prev);
    prev->next = newnode;
    tail->back = newnode;

    return head;
}


Node* inserteforekthelement(Node* head, int val , int k){
    if(k==1){
        return insertbeforehead(head,val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newnode = new Node(val,temp,prev);
    prev->next= newnode;
    temp->back = newnode;
    return head;
}

void insertbeforegivennode(Node* node, int val){
    Node* prev= node->back;
    Node* newnode = new Node(val,node,prev);
    prev->next = newnode;
    node->back = newnode;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = convertarr2dll(arr);
    print(head);

    head = deletehead(head);
    cout << endl;
    print(head);

    head = deletetail(head);
    cout << endl;
    print(head);

    head = deletekthelement(head, 4);
    cout << endl;
    print(head);

    deletenode(head->next);
    cout << endl;
    print(head);

    head = insertbeforehead(head, 40);
    cout << endl;
    print(head);

    head = insertbeforetail(head, 70);
    cout << endl;
    print(head);
    head = inserteforekthelement(head, 700,4);
    cout << endl;
    print(head);

    insertbeforegivennode(head->next->next,1200);
    cout << endl;
    print(head);
}
