#include<iostream>
#include<vector>

using namespace std;

int findconsecutiveones(vector<int>& nums){
    int max_it=0;
    int cnt=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            cnt++;
            max_it=max(max_it,cnt);
        }
        else{
            cnt=0;
        }
    }
    return max_it;
}

int main(){
    vector<int> arr={1,1,0,0,1,1,1,0,1,0,1,1,1,1};
    cout<<findconsecutiveones(arr)<<endl;

}