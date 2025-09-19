#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;

 //pairs

 void explainpair(){
    pair<int,int> p1={1,3};
    cout<< p1.first<<" "<<p1.second;
    pair<int , pair<int,int>> p2 = {1,{3,4}};
    cout<<p2.first<<" "<<p2.second.second<<" "<<p2.second.first;
    pair<int,int> arr[]={{1,2},{3,4},{5,6}};
    cout<< arr[1].second; 
 }


 void explainvector(){ //dynamic in nature, size is not constant
      vector<int> v;
      v.push_back(1);
      v.emplace_back(2);
       //faster than push_back
       v.insert(v.begin(),2,10);
      vector<pair<int,int>>vec;
      vec.push_back({1,2});
      vec.emplace_back(1,2);
      vector<int> v(5,100); //{100,100,100,100,100}
        
 }

int main(){

}


