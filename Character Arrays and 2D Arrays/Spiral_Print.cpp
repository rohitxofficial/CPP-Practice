#include <iostream>
using namespace std;

void SpiralPrint(int arr[][100], int n, int m)
{
    int row_top = 0;
    int col_right = m - 1;
    int row_bottom = n - 1;
    int col_left = 0;

    int count = 0;
    while (count < n * m)
    {
        for (int i = col_left; i <= col_right && count < n * m; i++)
        {
            cout << arr[row_top][i] << " ";
            count++;
        }

        for (int i = row_top + 1; i <= row_bottom - 1 && count < n * m; i++)
        {
            cout << arr[i][col_right] << " ";
            count++;
        }

        for (int i = col_right; i >= col_left + 1 && count < n * m; i--)
        {
            cout << arr[row_bottom][i] << " ";
            count++;
        }

        for (int i = row_bottom; i >= row_top + 1 && count < n * m; i--)
        {
            cout << arr[i][col_left] << " ";
            count++;
        }

        row_top++;
        col_right--;
        row_bottom--;
        col_left++;
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

    SpiralPrint(arr, n, m);

    return 0;
}