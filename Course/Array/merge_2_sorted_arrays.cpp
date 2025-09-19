#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void Mergesortedarrays(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int j=0;
    for(int i=0;i<(m+n);i++){
        if(nums1[i]==0){
            nums1[i]=nums2[j];
            j++;
        }
    }
    sort(nums1.begin(),nums1.end());
}



int main(){

    vector<int> a={1,2,3,0,0,0};
    int m=3;
    vector<int> b={2,5,6};
    int n=3;

    Mergesortedarrays(a,m,b,n);

    int size=a.size();
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }

}