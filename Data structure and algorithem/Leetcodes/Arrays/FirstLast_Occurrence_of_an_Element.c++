#include <iostream>
using namespace std;
int first0cc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid]){ // Right me jao s = mid + 1;
        s = mid + 1;
        }
        else if (key < arr[mid]){ // left me jao e = mid 1;
        e = mid -1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int last0cc(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid +1;
        }
        else if (key > arr[mid]){ // Right me jao s = mid + 1;
        s = mid + 1;
        }
        else if (key < arr[mid]){ // left me jao e = mid 1;
        e = mid -1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int even[8] = {1,2,3,3,3,3,3,5};
    cout << "first key index is : " << first0cc(even, 8, 3) << endl;
    cout << "last key index is : " << last0cc(even, 8, 3) << endl;

    return 0;
}