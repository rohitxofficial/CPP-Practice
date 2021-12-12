#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // creating heap
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;

        while (arr[childIndex] < arr[parentIndex] && childIndex != 0)
        {
            int temp = arr[childIndex];
            arr[childIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    // sorting heap
    for (int i = n - 1; i > 0; i--)
    {
        int firstIndex = 0;
        int lastIndex = i;

        int temp = arr[firstIndex];
        arr[firstIndex] = arr[lastIndex];
        arr[lastIndex] = temp;

        int parentIndex = 0;
        int child1 = 2 * parentIndex + 1;
        int child2 = 2 * parentIndex + 2;

        while (child1 < i)
        {
            if (child2 >= i)
            {
                if (arr[parentIndex] > arr[child1])
                {
                    int temp2 = arr[parentIndex];
                    arr[parentIndex] = arr[child1];
                    arr[child1] = temp2;
                }
                break;
            }
            else if (arr[parentIndex] < arr[child1] && arr[parentIndex] < arr[child2])
            {
                break;
            }
            else
            {
                int minElementIndex = (arr[child1] < arr[child2]) ? child1 : child2;

                int temp2 = arr[parentIndex];
                arr[parentIndex] = arr[minElementIndex];
                arr[minElementIndex] = temp2;

                parentIndex = minElementIndex;
                child1 = 2 * parentIndex + 1;
                child2 = 2 * parentIndex + 2;
            }
        }
    }

    print(arr, n);

    return 0;
}