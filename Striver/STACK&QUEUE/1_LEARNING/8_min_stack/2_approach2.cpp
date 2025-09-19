#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    int minim;
public:
    MinStack() {}

    void push(int val) {
        if(st.empty()){
            minim = val;
            st.push(val);
        } else {
            if(val >= minim){
                st.push(val);
            } else {
                // encode value
                st.push(2*val - minim);
                minim = val;
            }
        }
    }

    void pop() {
        if(!st.empty()) {
            int x = st.top();
            st.pop();
            if(x < minim) {
                // decode previous minimum
                minim = 2*minim - x;
            }
        }
    }

    int top() {
        if(st.empty()) return -1; // or throw exception
        int x = st.top();
        if(x >= minim) return x;
        return minim; // encoded value represents current min
    }

    int getMin() {
        if(st.empty()) return -1; // or throw exception
        return minim;
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(7);
    ms.push(3);
    ms.push(2);

    cout << "Top: " << ms.top() << endl;      // 2
    cout << "Min: " << ms.getMin() << endl;   // 2

    ms.pop();
    cout << "Top after pop: " << ms.top() << endl;    // 3
    cout << "Min after pop: " << ms.getMin() << endl; // 3

    ms.pop();
    cout << "Min after another pop: " << ms.getMin() << endl; // 5

    return 0;
}
