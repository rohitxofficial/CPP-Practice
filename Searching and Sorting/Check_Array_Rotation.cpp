#include <iostream>
using namespace std;

int CheckArrayRotation(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return i;
        }
    }
    return 0;
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

    cout << CheckArrayRotation(arr, n) << endl;

    return 0;
}