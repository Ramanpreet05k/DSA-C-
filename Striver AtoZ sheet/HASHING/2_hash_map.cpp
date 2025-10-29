#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>


#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
     map<int, int> mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
          mpp[arr[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
}