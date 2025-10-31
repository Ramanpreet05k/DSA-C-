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
    while (n1>0 && n2>0)
    {
       if(n1>n2){
        n1=n1%n2;
       }
     if(n2>n1){
        n2=n2%n1;
       }
    }
    if(n1==0){
        cout<<n2<<endl;
    }
    if(n2==0){
        cout<<n1<<endl;
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution(20,15);
}