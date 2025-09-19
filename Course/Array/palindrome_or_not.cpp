#include<iostream> cxz0 0
using namespace std;

int palindrome(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int arr[7]={1,2,3,5,3,2,1};
    if(palindrome(arr,7)){
        cout<<"Yes it is palindrome";
    }
    else{
        cout<<"No not a palindrome";
    }
}