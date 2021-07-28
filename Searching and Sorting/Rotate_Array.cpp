/*
You have been given a random integer array(arr) of size n. 
Write a function that rotates the given array by d elements(towards the left).
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

void RotateArray(int arr[], int n, int d)
{
    int p1_1 = 0;
    int p2_1 = d - 1;
    while (p1_1 < p2_1)
    {
        int temp = arr[p1_1];
        arr[p1_1] = arr[p2_1];
        arr[p2_1] = temp;
        p1_1++;
        p2_1--;
    }

    int p1_2 = d;
    int p2_2 = n - 1;
    while (p1_2 < p2_2)
    {
        int temp = arr[p1_2];
        arr[p1_2] = arr[p2_2];
        arr[p2_2] = temp;
        p1_2++;
        p2_2--;
    }

    int p1 = 0;
    int p2 = n - 1;
    while (p1 < p2)
    {
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
        p1++;
        p2--;
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

    int d;
    cin >> d;

    RotateArray(arr, n, d);

    PrintArray(arr, n);

    return 0;
}