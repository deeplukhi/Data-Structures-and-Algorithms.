#include<iostream>
using namespace std;

int sumArray(int arr[], int size) {

    if (size <= 0)
    {
        return 0;
    }
    
    return arr[size-1] + sumArray(arr, size - 1); 
    
    
}

int main(){
    int arr[5] = {1,4,5,6,7};
    cout << endl << endl << endl<< " sum of array is " <<sumArray(arr,5) << endl << endl << endl ;

    return 0;
}
