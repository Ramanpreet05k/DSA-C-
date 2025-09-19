#include<iostream>
using namespace std;

class Stack{
    int topval;
    int size;
    int * st;
    public:
    Stack(){
        topval=-1;
        size=1000;
        st= new int[size];
    }
    void push(int x){
        if(topval>=size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        topval=topval+1;
        st[topval]=x;
        cout<<x<<" pushed to stack"<<endl;
    }

    int top(){
        if(topval==-1){
            return -1;
        }
        else{
            return st[topval];
        }
    }

    void pop(){
        if(topval==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        int val = st[topval];
        topval=topval-1;
        cout<<val<<" popped"<<endl;
    }
    int getsize(){
        return topval+1;
    }
};

int main(){
    Stack s;
    s.push(20);
    s.push(40);
    s.pop();
   cout<<"Top Element: "<<s.top()<<endl;
   cout<<"Current Size: "<<s.getsize()<<endl;
}
