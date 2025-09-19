#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int missingnumberapp1(vector<int> arr,int k){
    for(int i=1;i<=k;i++){
        int flag=0;
        for(int j=0;j<k-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
       
    }
    return 0;
}

int missingnumberapp2(vector<int> arr, int k){
    unordered_map<int,int> sh(k+1);
    for(int i=0;i<k;i++){
    sh[arr[i]]=1;
    }
    for(int i=1;i<k;i++){
        if(sh[i]==0){
            return i;
        }
    }
    return 0;
}

int missingnumberapp3(vector<int> arr , int k){
    int val = 0;
    for(int i=1;i<=k;i++){
        val = val+i;
    }
    int val2=0;
    for(int i=0;i<k-1;i++){
        val2 = val2+ arr[i];
    }
    return val-val2;
}

//third approach
int missingNumber(vector<int> &a, int N){
    int xor1= 0;
    int xor2= 0;
    int n=N-1;
    for(int i=0;i<n;i++){
        xor2= xor2^a[i];
        xor1= xor1^(i+1);
    }
    xor1=xor1^N;
    return xor1^xor2;
}

int main(){
    int arr[4]={1,2,3,5};
    int n=5;

    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
          
        }
        if(flag==0){
            cout<<i;
            break;
        }
    }

    vector<int> a = {1,2,4,5};
    int ans = missingnumberapp3(a,5);
    cout<<endl<<ans<<endl;
}