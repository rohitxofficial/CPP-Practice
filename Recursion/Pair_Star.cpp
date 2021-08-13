#include <iostream>
using namespace std;

void MoveForward(char arr[])
{
    if (arr[0] == '\0')
    {
        arr[1] = '\0';
        return;
    }
    MoveForward(arr + 1);

    arr[1] = arr[0];
}

void PairStar(char arr[])
{
    if (arr[0] == '\0')
    {
        return;
    }

    if (arr[0] == arr[1])
    {
        MoveForward(arr + 1);
        arr[1] = '*';
    }

    PairStar(arr + 1);
}

int main()
{
    char arr[100];
    cin >> arr;

    PairStar(arr);

    cout << arr << endl;

    return 0;
}