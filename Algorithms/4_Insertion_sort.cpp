#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // For rand()

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The card we are currently picking up
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1;
        }
        
        // Place the key in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    // 1. Setup: Create a moderate dataset
    int n = 20000; 
    vector<int> data(n);

    // Seed random number generator
    srand(time(0));

    // Fill vector with RANDOM values
    for(int i = 0; i < n; i++) {
        data[i] = rand() % 100000;
    }

    cout << "Dataset size: " << n << endl;
    cout << "Sorting using Insertion Sort..." << endl;

    // --- START TIMING ---
    clock_t start_time = clock();

    // Perform the sort
    insertionSort(data);

    // --- END TIMING ---
    clock_t end_time = clock();

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Sort complete." << endl;
    cout << "Time taken: " << fixed << time_taken << " seconds" << endl;

    return 0;
}