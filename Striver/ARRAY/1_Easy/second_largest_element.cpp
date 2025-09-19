#include<iostream>
#include<vector>
using namespace std;
/* First Approach
int main(){
    int arr[5]={1,2,5,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int largest = 0;
    int seclarge= -1;

    for (int i=0;i<n;i++){
        if(largest<arr[i]){
            largest=arr[i];
        }
    }

    cout<<largest;

    for (int i=0;i<n;i++){
        if(seclarge<arr[i] && arr[i]!=largest){
            seclarge=arr[i];
        }
    }

    cout<<seclarge;

    
}*/

//Second Approach
int secondlargest(vector<int> &a,int n){
    int largest = a[0];
    int seclargest = -1;
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            seclargest=largest;
            largest=a[i];
            
        }
        else if(a[i]<largest && a[i]>seclargest){
            seclargest=a[i];
        }
    }
    return seclargest;
}

int secsmallest(vector<int> &a,int n){
    int smallest=a[0];
    int secsmallest = -1;
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            secsmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]<secsmallest && a[i]>smallest){
            secsmallest=a[i];
        }
    }
    return secsmallest;
}

