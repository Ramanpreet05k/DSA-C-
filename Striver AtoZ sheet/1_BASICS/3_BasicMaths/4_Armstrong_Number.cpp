#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void solution(int num){
        int orno= num;
        int temp = num;
        int armno = 0;
        int cnt=0;
        while(temp){
            temp=temp/10;
            cnt++;
        }
        while(num){
            int val = num%10;
            armno = armno+ pow(val, cnt);
            num = num/10;
        }
        if(armno == orno){
            cout<<orno<<" is Armstrong Number"<<endl;
        }
        else{
            cout<<orno<<" not Armstrong Number"<<endl;
        }
    }
};

int main(){
    int num=54748;
    Solution sol = Solution();
    sol.solution(num);
}