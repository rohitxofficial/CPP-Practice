#include <iostream>
using namespace std;

int length(char arr[])
{
    if (arr[0] == '\0')
    {
        return 0;
    }

    return 1 + length(arr + 1);
}

bool CheckPalindrome(char arr[], int st, int en)
{
    if (st > en)
    {
        return true;
    }

    if (arr[st] != arr[en])
    {
        return false;
    }

    return CheckPalindrome(arr, st + 1, en - 1);
}

int main()
{
    char arr[100];
    cin >> arr;

    if (CheckPalindrome(arr, 0, length(arr) - 1))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}