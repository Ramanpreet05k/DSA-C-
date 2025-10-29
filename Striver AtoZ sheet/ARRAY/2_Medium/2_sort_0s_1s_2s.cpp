#include<iostream>
#include<vector>
using namespace std;


/*first approach - sort the array by using sorting algo*/

void sort012a(vector<int>& arr){
    int n = arr.size();
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt0+=1;
        }
        else if(arr[i]==1){
            cnt1+=1;
        }
        else  if(arr[i]==2){
            cnt2+=1;
        }
    }
     for(int i=0;i<cnt0;i++){
            arr[i]=0;
        }
         for(int i=cnt0;i<cnt0+cnt1;i++){
            arr[i]=1;
        }
         for(int i=cnt0+cnt1;i<n;i++){
            arr[i]=2;
        }
}


void sort012_b(vector<int>& nums) {
        int n = nums.size();
        int mid = 0;
        int low = 0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }

int main(){
    vector<int> arr = {1,2,0,2,0,0,1,2,2,1,0,0,1};
    sort012a(arr);
    for(int num : arr){
        cout<<num;
    }
}