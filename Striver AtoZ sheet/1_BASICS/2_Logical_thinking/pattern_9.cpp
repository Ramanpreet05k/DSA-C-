#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int n) {
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

     for(int i=n;i>=0;i--){
        for(int j=i;j>=0;j--){
            cout<<"*";
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