/*
Given a 2D integer array with n rows and m columns.
Print the 0th row from input n times, 1st row n-1
times......(n-1)th row will be printed 1 time.
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n; k++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}