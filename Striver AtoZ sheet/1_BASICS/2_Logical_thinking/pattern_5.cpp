#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution(int n) {
    for(int i=n;i>=0;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
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