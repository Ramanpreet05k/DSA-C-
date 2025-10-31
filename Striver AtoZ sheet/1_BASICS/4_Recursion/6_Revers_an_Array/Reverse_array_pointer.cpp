#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;

class Solution
{
public:
  void solution(int l, int r, array<int, 5> &arr)
  {
    if(l>=r){
        return;
    }
    int temp = arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
    solution(l+1,r-1,arr);
  }
};

int main()
{
  Solution sol = Solution();
    array<int, 5> arr = {1, 2, 3, 4, 5};
  sol.solution(0,4,arr);
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<endl;
  }
}