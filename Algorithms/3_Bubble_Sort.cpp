#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); 
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int n = 20000; 
    vector<int> data(n);
    srand(time(0));
    for(int i = 0; i < n; i++) {
        data[i] = rand() % 100000; 
    }

    cout << "Dataset size: " << n << endl;
    cout << "Sorting using Bubble Sort..." << endl;

    clock_t start_time = clock();

    bubbleSort(data);

    clock_t end_time = clock();

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sort complete." << endl;
    cout << "Time taken: " << fixed << time_taken << " seconds" << endl;

    
    return 0;
}