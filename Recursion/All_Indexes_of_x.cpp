#include <iostream>
using namespace std;

void AllIndexes(int arr[], int n, int x, int arr2[])
{
    if (n == 0)
    {
        return;
    }

    if (arr[0] == x)
    {
        arr2[0]++;
    }

    AllIndexes(arr + 1, n - 1, x, arr2 + 1);
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

    int x;
    cin >> x;

    int arr2[100] = {0};

    AllIndexes(arr, n, x, arr2);

    bool AllZero = true;
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] != 0)
        {
            cout << i << " ";
            AllZero = false;
        }
    }

    if (AllZero)
    {
        cout << -1;
    }

    return 0;
}