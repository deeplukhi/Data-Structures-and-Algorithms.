#include <bits/stdc++.h>
using namespace std;

// Function to check if we can place 'k' cows with a minimum distance 'mid'
bool canWePlace(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= mid) {
            lastPosition = stalls[i];
            cowCount++;
            if (cowCount == k) 
            return true;
        }
    }
    return false;
}

// Function to find the largest minimum distance between cows placed in the stalls
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int min = 0;
    int max = stalls[n-1] - stalls[0];
    int result = 0; // To store the largest minimum distance

    while (min <= max) {
        int mid = min + (max - min) / 2;
        if (canWePlace(stalls, k, mid)) {
            result = mid; // Update result because we want the largest minimum distance
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return result;
}

int main() {
    // Example data
    vector<int> stalls = {1, 2, 8, 4, 9}; // Positions of the stalls
    int k = 3; // Number of cows

    // Function call to find the largest minimum distance
    int result = aggressiveCows(stalls, k);

    // Output the result
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
