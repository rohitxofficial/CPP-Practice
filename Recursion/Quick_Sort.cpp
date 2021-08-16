#include <iostream>
using namespace std;

int Partition(int arr[], int st, int en)
{
    int pivot = arr[st];

    int smallcount = 0;
    for (int i = st; i <= en; i++)
    {
        if (arr[i] < pivot)
        {
            smallcount++;
        }
    }

    int temp = arr[st + smallcount];
    arr[st + smallcount] = pivot;
    arr[st] = temp;

    int p1 = st;
    int p2 = en;

    while (p1 < st + smallcount && p2 > st + smallcount)
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
            int temp2 = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = temp2;
        }
    }

    return st + smallcount;
}

void QuickSort(int arr[], int st, int en)
{
    if (st >= en)
    {
        return;
    }

    int c = Partition(arr, st, en);
    QuickSort(arr, st, c - 1);
    QuickSort(arr, c + 1, en);
}

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    QuickSort(p, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}