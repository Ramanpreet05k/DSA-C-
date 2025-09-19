#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
                 int pos=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int indexval = j;
                    for(int x=j+1;x<nums2.size();x++){
                        if(nums2[j]<nums2[x]){
                            pos = nums2[x];
                            break;
                        }
                    }
                    break;
                }
            }
              ans.push_back(pos);
        }
          return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol = Solution();
    vector<int> nums1={4,1,2};
 vector<int> nums2={1,3,4,2};
      vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements: ";
    for(int x : result) {
        cout << x << " ";
    }
   
}