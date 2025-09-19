#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1) {
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        for(int i=nums1.size()-1;i>=0;i--){
            while(!st.empty()&& st.top()<=nums1[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(nums1[i]);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol = Solution();
 vector<int> nums2={1,3,4,2};
      vector<int> result = sol.nextGreaterElement(nums2);

    cout << "Next greater elements: ";
    for(int x : result) {
        cout << x << " ";
    }
   
}