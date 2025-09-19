#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;

    // helper: transfer all elements from s1 → s2
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            transfer();
        }

        if (s2.empty()) {
            cout << "Queue underflow!\n";
            return -1;
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            transfer();
        }

        if (s2.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();  // ✅ check both
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << "\n";   // 10
    cout << "Popped: " << q.pop() << "\n";  // 10
    cout << "Front after pop: " << q.peek() << "\n"; // 20
    cout << "Is empty? " << q.empty() << "\n"; // 0 (false)

    return 0;
}
