#include <iostream>
#include<set>
using namespace std;

vector<int> firstapproach(vector<int> arr){
      set<int> st(arr.begin(), arr.end());     
    int n = arr.size();
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int index = 0;
   vector<int> sol(st.begin(), st.end()); 
    for(auto it:st){
        sol[index] = it;
        index++;
    }
    return sol;
}

vector<int> secondapproach(vector<int> arr){
    int n=arr.size();
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return vector<int>(arr.begin(), arr.begin()+i+1);
}

int main()
{
    int arr[9] = {1, 1, 1, 2, 2, 2, 3, 3, 3};

    vector<int> vec = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    vector<int> st =firstapproach(vec);
    for(int i=0;i<st.size();i++){
        cout<<st[i]<<endl;
    }

    vector<int> st2 =secondapproach(vec);
    for(int i=0;i<st2.size();i++){
        cout<<st2[i]<<endl;
    }

   /* int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    

    cout << "Unique elements: ";
    for(int k = 0; k <= i; k++){
        cout << arr[k] << " ";
    }*/

}