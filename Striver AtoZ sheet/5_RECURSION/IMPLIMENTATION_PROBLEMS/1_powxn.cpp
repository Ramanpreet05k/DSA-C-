#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return -1;
        double temp = myPow(x,n/2);
        temp = temp*temp;
         if(n%2==0) return temp;
         if (n > 0) return temp * x;
        return temp / x;

    }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  int ans = sol.myPow(3,2);
  cout << ans;
}