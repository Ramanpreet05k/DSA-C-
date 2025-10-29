#include <iostream>
using namespace std;

class Queue {
    int currsize;
    int start;
    int end;
    int size;
    int* que;

public:
    // default constructor
    Queue() {
        size = 1000;
        que = new int[size];
        start = -1;
        end = -1;
        currsize = 0;
    }

    // parameterized constructor
    Queue(int s) {
        size = s;
        que = new int[size];
        start = -1;
        end = -1;
        currsize = 0;
    }

    // push element
    void push(int newelem) {
        if (currsize == size) {
            cout << "Queue is full.." << endl;
            return;
        }
        if (end == -1) { // first insertion
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        que[end] = newelem;   // store element
        currsize++;
        cout << newelem << " is pushed into queue" << endl;
    }

    // pop element
    int pop() {
        if (start == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int popped = que[start];
        if (currsize == 1) {  // removing last element
            start = end = -1;
            currsize = 0;
        } else {
            start = (start + 1) % size;
            currsize--;
        }
        return popped;
    }

    // front element
    int top() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return que[start];
    }

    // size of queue
    int getsize() {
        return currsize;
    }

    // check empty
    bool isEmpty() {
        return currsize == 0;
    }

    // destructor
    ~Queue() {
        delete[] que;
    }
};

int main() {
    Queue q(5);

    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front: " << q.top() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Front after pop: " << q.top() << endl;
    cout << "Current size: " << q.getsize() << endl;

    return 0;
}
