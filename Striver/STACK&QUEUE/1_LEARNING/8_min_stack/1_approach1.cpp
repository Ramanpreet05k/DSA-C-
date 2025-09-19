#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val, min(val,st.top().second)});
        }
    }
    
    void pop() {
        if(!st.empty())  
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(7);
    ms.push(3);
    cout<<"min val: "<<ms.getMin()<<endl;
    return 0;
}
