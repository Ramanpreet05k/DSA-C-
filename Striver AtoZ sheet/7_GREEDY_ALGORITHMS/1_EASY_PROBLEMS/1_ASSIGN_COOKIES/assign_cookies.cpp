#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    int assigncookies(vector<int> greed,vector<int> size){  
        sort(greed.begin(), greed.end());
        sort(size.begin(), size.end());
       int n=greed.size();
     int m=size.size();
     int l=0;
     int r=0;

     while (l<m && r < n)
     {
        if(greed[r]<=size[l]){
            r=r+1;
        }
        l=l+1;
     }
     return r;
     
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol = Solution();
    vector<int> greed = {1,1,2,2,3,4};
    vector<int> size = {1,3,3,4,5};
   cout<< sol.assigncookies(greed,size);
    cout<<endl;
}

// Time complexity = NlogN + MlogM + M