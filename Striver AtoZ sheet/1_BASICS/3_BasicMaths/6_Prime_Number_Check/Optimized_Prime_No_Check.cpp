#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
  void solution(int n)
  {
   int cnt=0;
   for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
        cnt++;
        if((n/i)==0){
            cnt++;
        }
    }
   }
   if(cnt!=0){
    cout<<n<<" is not a prime number"<<endl;
   }
   else{
    cout<<n<<" is a prime number"<<endl;
   }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(10007);
}