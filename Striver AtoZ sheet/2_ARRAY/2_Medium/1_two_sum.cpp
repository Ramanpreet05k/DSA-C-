#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> twosum1(vector<int> arr, int target){
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int val1 = arr[i];
        for(int j=i+1;j<n;j++){
            if(val1+arr[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

vector<int> twosum2(vector<int> arr , int target){
    int n = arr.size();
    vector<int> ans;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int more = target-a;
        if(mpp.find(more)!=mpp.end()){
             ans.push_back(mpp[more]);
            ans.push_back(i);
        }
        else{
            mpp[a]=i;
        }
    }
    return ans;
}

/*
In third approach, sort the array and than use two pointers
one at starting and one at ending
compare the sum of values at pointers with target
if target greater than move right pointer backward
else move left pointer forward
when sum == target -> return true else false
*/

int main(){
    vector<int> arr = {2,6,5,8,11};
    vector<int> ans = twosum2(arr,17);
    for(int num: ans){
        cout<<num<<endl;
    }
}