#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int n) {
    int num=n;
    for(int i=0;i<n;i++){
       //space
       for(int j=0;j<i;j++){
        cout<<" ";
       }
       //star
       for(int j=0;j<2*n-(2*i +1);j++){
        cout<<"*";
       }

       //space
       for(int j=0;j<i;j++){
        cout<<" ";
       }
       cout<<endl;
    }
  }
};

int main()
{
  int n;
  cout<<"Enter n: ";
  cin>>n;
  Solution sol = Solution();
  sol.solution(n);
}