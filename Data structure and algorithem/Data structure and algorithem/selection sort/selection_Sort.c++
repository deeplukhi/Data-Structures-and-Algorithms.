#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    // Initialize a vector of integers
    vector<int> arr = {64, 25, 12, 22, 11};

    // Get the size of the array
    int n = arr.size();

    // Print the array before sorting
    cout << "Unsorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the selection sort function
    selectionSort(arr, n);

    // Print the array after sorting
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
