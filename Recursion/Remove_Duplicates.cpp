#include <iostream>
using namespace std;

void MoveBackwards(char arr[])
{
    if (arr[1] == '\0')
    {
        arr[0] = arr[1];
        return;
    }

    arr[0] = arr[1];
    MoveBackwards(arr + 1);
}

void RemoveDuplicates(char arr[])
{
    if (arr[0] == '\0')
    {
        return;
    }

    if (arr[0] == arr[1])
    {
        MoveBackwards(arr);
        RemoveDuplicates(arr);
    }
    else
    {
        RemoveDuplicates(arr + 1);
    }
}

int main()
{
    char arr[100];
    cin >> arr;

    RemoveDuplicates(arr);

    cout << arr << endl;

    return 0;
}