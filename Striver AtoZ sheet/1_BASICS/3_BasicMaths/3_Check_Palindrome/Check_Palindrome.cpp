#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
    void solution(int &num){
        int val = num;
        int revnum=0;
        while(num!=0){
            int val = num%10;
            num=num/10;
            revnum = (revnum*10) + val;
        }
        if(revnum== val){
            cout<<"YES IT IS PALINDROME"<<endl;
        }
        else{
            cout<<"NOT A PALINDROME"<<endl;
        }
    }
};

int main(){
    int num=1234321;
    Solution sol = Solution();
    sol.solution(num);
}