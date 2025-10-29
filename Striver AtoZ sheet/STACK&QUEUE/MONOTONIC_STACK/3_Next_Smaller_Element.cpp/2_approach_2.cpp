#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums1) {
        int n= nums1.size();
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i=0;i<=n-1;i++){
            while(!st.empty() && st.top()>=nums1[i]){
                st.pop();
            }
            nge[i]=st.empty()?-1:st.top();
            st.push(nums1[i]);
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