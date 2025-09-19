#include<iostream>
#include<vector>
using namespace std;


void movezeros1(vector<int>& arr){
    int n = arr.size();
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
}

void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                int val=nums[i];
                nums[i]=nums[j];
                nums[j]=val;
                i++;
            }
        }
    }

int main(){
   vector<int> arr = {1,0,2,3,4,0,5,0};
   moveZeroes(arr);
   for(int i=0;i<arr.size();i++){
    cout<<arr[i];
   }
}