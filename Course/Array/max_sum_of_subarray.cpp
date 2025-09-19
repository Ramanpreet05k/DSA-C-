#include<iostream>
using namespace std;

int main(){
    int arr[5]={2,-1,3,4,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    //First Approach
    int ans=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for (int j=i;j<n;j++){
            sum=sum+arr[j];
            ans = max(sum,ans);
        }
    }
    cout<<ans<<endl;



    //second approach: KADANE'S ALGORITHM
    int maxno = INT16_MIN;
    int prev=0;
    for(int i=0;i<n;i++){
        if(prev + arr[i] > arr[i]){
            prev+=arr[i];
        }
        else{
            prev=arr[i];
        }
        maxno = max(prev,maxno);
    }
    cout<<maxno;

}