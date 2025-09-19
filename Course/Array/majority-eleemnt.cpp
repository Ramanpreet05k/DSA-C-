#include<iostream>
#include <map>
using namespace std;

int main(){
    int arr[6]={1,2,3,1,1,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    map <int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if (freq[arr[i]]>n/2){
            cout<<arr[i];
            break;
        }
    }

}