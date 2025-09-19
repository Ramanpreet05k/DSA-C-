#include<iostream>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    int d=4;

    for(int i=0;i<n;i++){
        if(arr[i]==d){
            cout<<i;
            break;
        }
    }
}