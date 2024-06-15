#include <bits/stdc++.h>
using namespace std;

int countStudent(vector<int>& arr, int pages) {
    int studentCount = 1;
    long long pagecount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (pagecount + arr[i] <= pages) {
            pagecount += arr[i];
        } else {
            studentCount++;
            pagecount = arr[i];
        }
    }
    return studentCount;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int students = countStudent(arr, mid);
        
        if (students > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2; // Number of students
    cout << "Minimum number of pages: " << findPages(arr, n, m) << endl;
    return 0;
}
