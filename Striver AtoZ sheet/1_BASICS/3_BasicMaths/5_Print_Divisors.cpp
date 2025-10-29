#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void solution(int num){ 
        int cnt=1;
        while(cnt<=num){
            if(num%cnt==0){
                cout<<cnt<<" ";
            }
                cnt++;
        }
    }
};

int main(){
    int num=12;
    Solution sol = Solution();
    sol.solution(num);
}