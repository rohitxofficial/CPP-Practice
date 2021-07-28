/*
You are given an integer array(arr) of size n. It contains only 0s, 1s and 2s. 
Write a solution to sort this array in a 'single scan'. 'Single Scan' refers to 
iterating over the array just once or to put it in other words, 
you will be visiting each element in the array/list just once.
*/

#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Sort012(int arr[], int n)
{
    int p1 = 0;
    int p2 = 0;
    int p3 = n - 1;
    while (p2 <= p3)
    {
        if (arr[p1] == 0)
        {
            p1++;
        }

        if (arr[p3] == 2)
        {
            p3--;
        }

        if (arr[p2] == 0 && arr[p1] != 0 && p2 > p1)
        {
            int temp = arr[p2];
            arr[p2] = arr[p1];
            arr[p1] = temp;
        }
        else if (arr[p2] == 2 && arr[p3] != 2)
        {
            int temp = arr[p2];
            arr[p2] = arr[p3];
            arr[p3] = temp;
        }
        else
        {
            p2++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Sort012(arr, n);

    PrintArray(arr, n);

    return 0;
}