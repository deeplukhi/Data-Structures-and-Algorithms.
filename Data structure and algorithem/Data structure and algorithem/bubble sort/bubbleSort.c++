#include <bits/stdc++.h>
using namespace std;

// Function to perform Bubble Sort on the vector
void bubbleSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
