#include<iostream>
using namespace std;

int main(){
    int arr[10]={1,2,3,4,2,6,7,8,9,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<=n;i++){
        if(arr[i]<arr[i-1]){
            cout<<"Array is not sorted";
            return 0;

        }
    }
    cout<<"Array is sorted";
    return 1;

}