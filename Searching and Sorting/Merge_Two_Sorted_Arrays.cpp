/*
You have been given two sorted arrays(arr1 and arr2) of size n and m respectively, 
merge them into a third array such that the third array is also sorted.
*/

#include <iostream>
#include <climits>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MergeArray(int arr1[], int arr2[], int arr3[], int n, int m)
{
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    while (p3 < m + n)
    {
        if (p1 > n - 1)
        {
            for (int i = p2; p2 < m; p2++)
            {
                arr3[p3] = arr2[p2];
                p3++;
            }
            break;
        }

        if (p2 > m - 1)
        {
            for (int i = p1; p1 < n; p1++)
            {
                arr3[p3] = arr1[p1];
                p3++;
            }
            break;
        }

        if (arr1[p1] < arr2[p2])
        {
            arr3[p3] = arr1[p1];
            p1++;
        }
        else if (arr1[p1] > arr2[p2])
        {
            arr3[p3] = arr2[p2];
            p2++;
        }
        else
        {
            arr3[p3] = arr1[p1];
            p3++;
            arr3[p3] = arr2[p2];
            p1++;
            p2++;
        }
        p3++;
    }
}

int main()
{
    int n, m;
    cin >> n;

    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cin >> m;
    int arr2[m];

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    int arr3[n + m];

    MergeArray(arr1, arr2, arr3, n, m);
    PrintArray(arr3, n + m);

    return 0;
}