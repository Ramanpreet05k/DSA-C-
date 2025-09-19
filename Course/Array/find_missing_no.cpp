#include<iostream>
using namespace std;

int main(){
    
    int arr[4]={1,2,3,5};

    int n = sizeof(arr) / sizeof(arr[0]);


    //First approach 
    for(int i=1;i<n+1;i++){
       int flag = 0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                flag=1;
            }
           
        }
        if(flag==0){
            cout<<i<<endl;
        }
    }
    
    //second approach
    int totalsum = ((n + 1) * (n + 2)) / 2;

    for(int i = 0; i < n; i++){
        totalsum -= arr[i];
    }

    cout << "Missing number is: " << totalsum << endl;


    //third approach
    int a[n+1]={0};
    for(int i=0;i<n;i++){
        a[arr[i]-1]=1;
    }
    for(int i=0;i<n+1;i++){
        if(a[i]==0){
            cout<<i+1;
        }
    }

    return 0;
}