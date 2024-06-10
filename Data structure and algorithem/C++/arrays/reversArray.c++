#include <iostream>
#include <algorithm> // Required for std::swap

using namespace std;

void REVERSE(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void displayarry(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{

    cout << endl
         << "welcome to the array display" << endl;

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int brr[8] = {6, 5, 8, 9, 3, 2};

     REVERSE(arr, 10);
    REVERSE(brr, 8);

    displayarry(arr, 10);
    displayarry(brr, 8);
    cout << endl
         << "welcome to the array reverse" << endl;

       displayarry(arr, 10);
    displayarry(brr, 8);

    return 0;
}