#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int walls) {
    int painterCount = 1;
    int wallsCount = 0;
    for(int i = 0; i < boards.size(); i++) { // Corrected comma to semicolon
        if(wallsCount + boards[i] <= walls) { // Corrected arr to boards
            wallsCount += boards[i]; // Corrected =+ to +=
        } else {
            painterCount++;
            wallsCount = boards[i]; // Corrected arr to boards
        }
    }
    return painterCount;
}


int findLargestMinDistance(vector<int> &boards, int k){
    if(k> boards.size()) return -1;
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);

    while(low<=high){
        int mid = (low+high)/2;
        int painters = countPainters(boards, mid);
        if(painters > k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    std::vector<int> boards = {10, 20, 30, 40};
    int k = 2; // Number of painters

    int result = findLargestMinDistance(boards, k);
    std::cout << "The largest minimum distance is: " << result << std::endl;

    return 0;
}
