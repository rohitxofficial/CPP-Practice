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

int TentoPow(int n)
{
    if (n == 1)
    {
        return 10;
    }
    return 10 * TentoPow(n - 1);
}

int StringtoInt(char arr[], int n)
{
    if (n == 0)
    {
        return arr[0] - 48;
    }

    int ans = StringtoInt(arr + 1, n - 1);

    return (TentoPow(n) * (arr[0] - 48)) + ans;
}

int main()
{
    char arr[100];
    cin >> arr;

    int len = length(arr);

    cout << StringtoInt(arr, len - 1) << endl;

    return 0;
}