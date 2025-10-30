#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
    void solution(int &num){
        int revnum=0;
        while(num!=0){
            int val = num%10;
            num=num/10;
            revnum = (revnum*10) + val;
        }
        cout<< "Reverse Number: "<<revnum<<endl;
    }
};

int main(){
    int num=12345;
    Solution sol = Solution();
    sol.solution(num);
}