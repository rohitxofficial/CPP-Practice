#include <iostream>
using namespace std;

int partition(int arr[], int st, int en)
{
    int pivot = arr[st];

    int smallCount = 0;

    for (int i = st; i <= en; i++)
    {
        if (arr[i] < pivot)
            smallCount++;
    }

    int temp = arr[st + smallCount];
    arr[st + smallCount] = pivot;
    arr[st] = temp;

    int p1 = st;
    int p2 = en;
    while (p1 < st + smallCount && p2 > st + smallCount)
    {
        if (arr[p1] < pivot)
        {
            p1++;
        }
        else if (arr[p2] >= pivot)
        {
            p2--;
        }
        else
        {
            int temp2 = arr[p2];
            arr[p2] = arr[p1];
            arr[p1] = temp2;
        }
    }

    return st + smallCount;
}

void sort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }

    int pivot_pos = partition(arr, st, en);
    sort(arr, st, pivot_pos - 1);
    sort(arr, pivot_pos + 1, en);
}

int main()
{
    int n1;
    cin >> n1;

    int *arr1 = new int[n1];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;

    int *arr2 = new int[n2];

    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    sort(arr1, 0, n1 - 1);
    sort(arr2, 0, n2 - 1);

    int p1 = 0;
    int p2 = 0;

    while (p1 < n1 && p2 < n2)
    {
        if (arr1[p1] > arr2[p2])
            p2++;
        else if (arr1[p1] < arr2[p2])
            p1++;
        else
        {
            cout << arr1[p1] << " ";
            p1++;
            p2++;
        }
    }
    cout << endl;

    delete arr1;
    delete arr2;

    return 0;
}
