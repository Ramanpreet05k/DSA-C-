#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
  void solution(int sum , int n)
  {
   if(n<1){ 
    cout<<sum<<endl;
    return ;
   }
   solution(sum+n,n-1);
  
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(0,5);
}