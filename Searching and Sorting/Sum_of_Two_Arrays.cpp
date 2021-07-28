/*
Two random integer arrays have been given as arr1 and arr2 of size n and m respectively. 
Both the arrays contain numbers from 0 to 9(i.e. single digit integer is present at every index). 
The idea here is to represent each array as an integer in itself of digits n and m.
You need to find the sum of both the input arrays treating them as two integers and 
put the result in another array i.e. output array will also contain only single digit at every index.
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

void InputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void SumofTwoArrays(int arr1[], int arr2[], int sum[], int n, int m, int sum_size)
{
    int p1 = n - 1;
    int p2 = m - 1;
    int p3 = sum_size - 1;

    int carry = 0;
    while (p3 >= 0)
    {
        int total = 0;
        if (p1 >= 0)
        {
            total += arr1[p1];
        }
        if (p2 >= 0)
        {
            total += arr2[p2];
        }
        total += carry;

        if (total < 10)
        {
            sum[p3] = total;
            carry = 0;
        }
        else
        {
            sum[p3] = total % 10;
            carry = total / 10;
        }

        p1--;
        p2--;
        p3--;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr1[n];
    InputArray(arr1, n);

    int m;
    cin >> m;
    int arr2[m];
    InputArray(arr2, m);

    int sum_size = ((n > m) ? n : m) + 1;
    int sum[sum_size] = {0};
    SumofTwoArrays(arr1, arr2, sum, n, m, sum_size);

    PrintArray(sum, sum_size);

    return 0;
}