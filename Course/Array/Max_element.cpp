#include<iostream>
using namespace std;

int main(){

    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"Array will be"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    int max=arr[0];

    for(int i=0;i<5;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    cout<<"Max eleement: "<<max<<endl;

return 0;
}