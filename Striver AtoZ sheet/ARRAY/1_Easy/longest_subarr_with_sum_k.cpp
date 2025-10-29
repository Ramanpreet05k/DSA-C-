#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestsubarray1(vector<int> arr, int val) {
    int n = arr.size();
    int length = 0;

    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += arr[j];  // accumulate sum
            if (s == val) {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

int longestsubarray2(vector<int> arr, long long k){
    map<long long, int> presummap;
    long long sum=0;
    int maxLen = 0;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];  
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        int rem = sum-k;
        if(presummap.find(rem)!=presummap.end()){
            int len = i-presummap[rem];
            maxLen=max(maxLen, len);
        }
        if(presummap.find(sum)==presummap.end())
        presummap[sum]=i;
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << longestsubarray2(arr, 6);
}
