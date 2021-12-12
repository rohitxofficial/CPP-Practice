#include <iostream>
using namespace std;

bool checkMaxHeap(int *arr, int n, int parentIndex)
{
    int child1 = 2 * parentIndex + 1;
    int child2 = 2 * parentIndex + 2;
    if (child1 >= n)
        return true;

    if (child2 >= n)
    {
        return arr[child1] < arr[parentIndex];
    }

    if (arr[child1] < arr[parentIndex] && arr[child2] < arr[parentIndex])
    {
        return checkMaxHeap(arr, n, child1) && checkMaxHeap(arr, n, child2);
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (checkMaxHeap(arr, n, 0))
        cout << "true";
    else
        cout << "false";

    return 0;
}