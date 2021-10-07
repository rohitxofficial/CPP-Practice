#include <iostream>
using namespace std;

void rotateArray(int arr[], int length, int index)
{
    int p1 = 0;
    int p2 = index - 1;

    while (p1 < p2)
    {
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;

        p1++;
        p2--;
    }

    p1 = index;
    p2 = length - 1;

    while (p1 < p2)
    {
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;

        p1++;
        p2--;
    }

    p1 = 0;
    p2 = length - 1;

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

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index;
    cin >> index;

    rotateArray(arr, n, index);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}