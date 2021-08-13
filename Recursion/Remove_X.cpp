#include <iostream>
using namespace std;

void MoveBack1(char arr[])
{
    if (arr[0] == 0)
    {
        return;
    }

    arr[0] = arr[1];

    MoveBack1(arr + 1);
}

void RemoveX(char arr[])
{
    if (arr[0] == '\0')
    {
        return;
    }

    RemoveX(arr + 1);

    if (arr[0] == 'x')
    {
        MoveBack1(arr);
    }
}

int main()
{
    char arr[100];
    cin >> arr;

    RemoveX(arr);

    cout << arr << endl;

    return 0;
}