#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int linearSearch( vector<int>& arr , int target){
    for(size_t i=0;i< arr.size(); i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int n = 100000;
    int val, target;
    cout<<"Enter no of values in vector: "<<endl;
    cin>>val;
    vector<int> data(n);
    for(int i=0;i<val;i++){
        cin>>data[i];
    }
    
    cout<<"Enter target : ";
    cin>>target;
    clock_t start_time = clock();
    int result = linearSearch(data, target);
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    cout << "Time taken: " << fixed << time_taken << " seconds" << endl;

    return 0;

}