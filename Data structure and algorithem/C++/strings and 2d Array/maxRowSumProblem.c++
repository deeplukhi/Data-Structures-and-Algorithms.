#include<iostream>
using namespace std;

    int maxRowSumIndex(int arr[][3], int row, int col){
        int maxi = INT16_MIN;
        int index = -1;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        
            if (sum > maxi)
            {
                maxi = sum;
                index = i;
            }
    }
    cout << " max sum of row is " << maxi << endl;
    cout << " row of max sum is "<< index << endl;
 }
    

 int printSumRow(int arr[][3], int row, int col){
     cout << " printing sum of row elements............" << endl;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
 }

 int printSumcol(int arr[][3], int row, int col){
     cout << " printing sum of row elements............" << endl;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
 }


int main(){

    int arr[3][3];
    cout << "enter elements............" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    cout << " printing elements............" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    printSumRow(arr, 3, 3);
    printSumcol(arr, 3, 3);
    maxRowSumIndex(arr, 3, 3);

    return 0;
}