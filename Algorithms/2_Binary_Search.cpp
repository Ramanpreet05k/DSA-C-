#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = 6; 
    vector<int> data(n);
    for(int i = 0; i < n; i++) {
        data[i] = i;
    }
    int target = n - 1; 

    cout << "Dataset size: " << n << endl;
    cout << "Searching for target: " << target << "..." << endl;
    clock_t start_time = clock();
    int result = binarySearch(data, target);
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