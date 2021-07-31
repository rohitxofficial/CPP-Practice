/*
For a given two-dimensional integer array of size (n x m), 
you need to find out which row or column has the largest 
sum(sum of all the elements in a row/column) amongst all 
the rows and columns.
*/

#include <iostream>
using namespace std;

void LargestRoworCol(int arr[][100], int n, int m)
{
    bool rowcol = false;
    int index = 0;
    int sum = -2147483648;

    for (int i = 0; i < n; i++)
    {
        int sum_temp = 0;
        for (int j = 0; j < m; j++)
        {
            sum_temp += arr[i][j];
        }
        if (sum_temp > sum)
        {
            index = i;
            sum = sum_temp;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int sum_temp = 0;
        for (int j = 0; j < n; j++)
        {
            sum_temp += arr[j][i];
        }
        if (sum_temp > sum)
        {
            index = i;
            sum = sum_temp;
            rowcol = true;
        }
    }

    if (rowcol)
    {
        cout << "col " << index << " " << sum << endl;
    }
    else
    {
        cout << "row " << index << " " << sum << endl;
    }
}

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

    LargestRoworCol(arr, n, m);

    return 0;
}