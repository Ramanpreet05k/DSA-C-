#include<iostream>
#include<vector>
#include<map>
using namespace std;


int majorityelem1(vector<int> arr){
    int n = arr.size();
    int target = n/2;
    for(int i=0;i<n;i++){
        int val = arr[i];
        int cnt=0;
        for(int j=0;j<n;j++){
            if(val==arr[j]){
                cnt++;
            }
        }
        if(cnt>target){
            return val;
        }
    }
    return -1;
};

int majorityelem2(vector<int> arr){
    int n = arr.size();
    int target = n/2;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
         mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second>target){
            return it.first;
        }
    }
    return -1;
}

int majorityelem3(vector<int> arr){
    int n = arr.size();
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el = arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el) cnt++;
    }
    if(cnt>(arr.size()/2)){
        return el;
    }
    return -1;
}

int main(){
    vector<int> arr = {3,2,3,2,2};
    cout<< majorityelem3(arr);
}