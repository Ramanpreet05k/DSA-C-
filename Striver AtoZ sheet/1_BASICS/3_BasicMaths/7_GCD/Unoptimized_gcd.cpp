#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
  void solution(int n1, int n2)
  {
    int val = 1;
    for(int i=1;i<=min(n1,n2);i++){
        if(n1%i==0 && n2%i==0){
            val = i;
        }
    }
    cout<<val<<endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(8,12);
}