/*
You have been given a random integer array(arr) of size n. 
You are required to find and return the second largest element 
present in the array. If N <= 1 or all the elements are same in 
the array then return -2147483648(smallest value for the range of Integer).
*/

#include <iostream>
#include <climits>
using namespace std;

int SecondLargest(int arr[], int n)
{
    bool flag = false;
    int secondLargest = INT_MIN;
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
        else if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
    }
    return secondLargest;
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

    cout << SecondLargest(arr, n) << endl;

    return 0;
}