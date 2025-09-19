#include<iostream>
#include<vector>

using namespace std;


    class MyStack {
    queue<int> q; // class member

public:
    MyStack() {}

    void push(int x) {
        q.push(x);  // first push new element
        int s = q.size();
        // Rotate so new element comes to the front
        for (int i = 0; i < s - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout<<x<<" pushed to stack"<<endl;
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack underflow!\n";
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


int main(){
    MyStack ms;
    ms.push(10);
    ms.push(30);
    ms.push(50);
    cout<<ms.pop()<<endl;
}