#include<iostream>
using namespace std;

int noappearingones1(vector<int> nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        int val = nums[i];
        int cnt =0;
        for(int j=0;j<n;j++){
            if(nums[j]==val){
                cnt++;
            }
        }
        if(cnt==1){
            return val;
        }
    }
    return -1;
}

int noappearingones2(vector<int> nums){
    int n = nums.size();
    int max_val = nums[0];
    for(int i=1;i<n;i++){
        if(max_val<nums[i]){
            max_val = nums[i];
        }
    }
    unordered_map<int,int> hashmap(max_val);
    for(int i=0;i<n;i++){
        hashmap[nums[i]]++;
    }
     for(int i=0;i<n;i++){
        if(hashmap[nums[i]]==1){
            return nums[i];
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5,6,6,7};
    int ans = noappearingones2(arr);
    cout<<ans;

}