#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
  int solution(int n)
  {
  if(n==0){
    
    return 0;
  }
  return n + solution(n-1);
  }
};

int main()
{
  Solution sol = Solution();
  cout<<sol.solution(5);
}