#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums1) {
        int n= nums1.size();
        vector<int> nge(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums1[i]>nums1[j]){
                    nge[i]=nums1[j];
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
      vector<int> result = sol.nextSmallerElement(nums2);

    cout << "Next smaller elements: ";
    for(int x : result) {
        cout << x << " ";
    }
   
}