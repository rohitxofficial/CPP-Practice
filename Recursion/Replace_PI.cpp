#include <iostream>
using namespace std;

void MoveForward2(char arr[])
{
    if (arr[0] == '\0')
    {
        arr[2] = '\0';
        return;
    }

    MoveForward2(arr + 1);
    arr[2] = arr[0];
}

void ReplacePI(char arr[])
{
    if (arr[0] == '\0')
    {
        return;
    }

    if (arr[0] == 'p' && arr[1] == 'i')
    {
        MoveForward2(arr);
        arr[0] = '3';
        arr[1] = '.';
        arr[2] = '1';
        arr[3] = '4';

        ReplacePI(arr + 4);
    }
    else
    {
        ReplacePI(arr + 1);
    }
}

int main()
{
    char arr[100];
    cin >> arr;

    ReplacePI(arr);

    cout << arr << endl;

    return 0;
}