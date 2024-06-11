#include <iostream>
using namespace std;
int getPivot (int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[0]<=arr[mid]){
            s = mid + 1;
        }else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return e;
}
int main() {
cout <<endl<< "every thing is all okay "<< endl;
int arr[6] = {6,7,0,1,2,3};
cout << "pivot element at indext of : "<< getPivot(arr,6)<< endl<<endl;
return 0;

}