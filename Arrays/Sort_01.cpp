/*
You have been given an integer array(arr) of size N that contains only integers, 0 and 1. 
Write a function to sort this array. Think of a solution which scans the array only once 
and don't require use of an extra array.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int ls = n - 1;

    while (st < ls)
    {
        if (arr[st] == 1 && arr[ls] == 0)
        {
            int temp = arr[st];
            arr[st] = arr[ls];
            arr[ls] = temp;
        }
        if (arr[st] == 0)
        {
            st++;
        }
        if (arr[ls] == 1)
        {
            ls--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}