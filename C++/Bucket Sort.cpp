#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform insertion sort within each bucket
void insertionSort(vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; ++i) {
        int key = bucket[i];
        int j = i - 1;
        
        // Move elements of bucket[0..i-1] that are greater than key
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    
    // Find the maximum and minimum elements in the array
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    
    // Calculate the range of values
    int range = maxVal - minVal + 1;
    
    // Create buckets
    vector<vector<int>> buckets(range);
    
    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        int index = arr[i] - minVal;
        buckets[index].push_back(arr[i]);
    }
    
    // Sort each bucket using insertion sort
    for (int i = 0; i < range; ++i) {
        insertionSort(buckets[i]);
    }
    
    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < range; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    bucketSort(arr);
    
    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    cout << endl;
    
    return 0;
}
