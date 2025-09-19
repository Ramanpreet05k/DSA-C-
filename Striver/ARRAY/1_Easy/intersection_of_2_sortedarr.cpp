#include<iostream>
#include<vector>
using namespace std;

//second approach


vector<int> intersectionarray1(vector<int> arr1 , vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> ans;
    vector<int> vis(n2);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j] && vis[j]==0){
                ans.push_back(arr1[i]);
                vis[j]=1;
                break;
            }
            if(arr2[j]>arr1[i]){
                break;
            }
        }
    }
    return ans;
}
vector<int> Intersection(vector<int> &a, int n, vector<int> &b, int m){
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    int arr1[8]={1,2,2,3,3,4,5,6};
    int arr2[7]={2,3,3,5,6,6,7};

    vector<int> a1={1,2,2,3,3,4,5,6};
    vector<int> a2={2,3,3,5,6,6,7};

    int n1= sizeof(arr1)/sizeof(arr1[0]);
    int n2= sizeof(arr2)/sizeof(arr2[0]);
    vector<int> arrvisited(n2);
   vector<int> ans;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]==arr2[j] && arrvisited[j]==0 ){
                ans.push_back(arr1[i]);
                arrvisited[j]=1;
                break;
            }
            if(arr2[j]>arr1[i]){
                break;
            }
        }
    }

    cout << "Intersection of arrays: ";
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    
vector<int> sol = intersectionarray1(a1,a2);
cout << "Intersection of arrays: ";
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;


}