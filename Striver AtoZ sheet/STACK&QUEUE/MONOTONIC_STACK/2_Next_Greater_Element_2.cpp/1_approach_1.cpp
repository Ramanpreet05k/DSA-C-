#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1) {
        int n= nums1.size();
        vector<int> nge(n,-1);
        for(int i=0;i<=n-1;i++){
            for(int j=i+1;j<=(i+n-1);j++){
                int ind = j%n;
                if(nums1[ind]>nums1[i]){
                    nge[i]=nums1[ind];
                    break;  
                }
            }
        }
        return nge;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol = Solution();
 vector<int> nums2={2,10,12,1,11};
      vector<int> result = sol.nextGreaterElement(nums2);

    cout << "Next greater elements: ";
    for(int x : result) {
        cout << x << " ";
    }
   
}