#include <iostream>
using namespace std;

int findUnique(int *arr, int size){
    int ans = 0;
    for(int i = 0; i< size; i++){
        ans = ans^arr[i];
    } return ans;
} 

int main(){
    int even[8] = {2,3,4,5,6,7,7,8};
    findUnique(even,8);
    cout << findUnique << endl;
}   