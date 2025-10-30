#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    void solution(int &num){
        int cnt = 0;
        while(num!=0){
         
            num= num/10;
            cnt++;
        }
        cout<< "COUNT: "<< cnt<<endl;
    }
};

int main(){
    int num=12345;
    Solution sol = Solution();
    sol.solution(num);
}