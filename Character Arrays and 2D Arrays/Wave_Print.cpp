/*
For a given two-dimensional integer array of size (n x m), print the array 
in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.
*/

#include <iostream>
using namespace std;

void WavePrint(int arr[][100], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    WavePrint(arr, n, m);

    return 0;
}