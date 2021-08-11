#include <iostream>
using namespace std;

int SumArray(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    return arr[0] + SumArray(arr + 1, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << SumArray(arr, n) << endl;

    return 0;
}