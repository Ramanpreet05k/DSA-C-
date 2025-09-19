 #include<iostream>
#include<vector>
using namespace std;
 

void reverse(vector<int>& arr, int start, int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}


vector<int> rotatedplaces(vector<int> arr, int d){
int n = arr.size();
d = d%n;
vector<int> temp(d);

for(int i=0;i<d;i++){
    temp[i]=arr[i];
}
for (int i=d;i<n;i++){
    arr[i-d]=arr[i];
}


for(int i=n-d;i<n;i++){
    arr[i]=temp[i-(n-d)];
}

return arr;
}

vector<int> rotatedplaces_2(vector<int> arr,int d){
    int n = arr.size();
    d=d%n;
        reverse(arr, 0, d-1);
     reverse(arr, d, n-1);
    reverse(arr, 0, n-1);

    return arr;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    vector<int> ans = rotatedplaces_2(arr,2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    /*int n = sizeof(arr)/sizeof(arr[0]);
    int d;

    cout<<"Enter no of rotations: ";
    cin>>d;
    d = d % n;
    vector<int> temp(d);

    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }

    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    int j=0;
    for(int i=n-d;i<n;i++){
        arr[i]=temp[j];

        j++;
    }



    for(int i=0;i<n;i++){
        cout<<arr[i];
    }*/


}