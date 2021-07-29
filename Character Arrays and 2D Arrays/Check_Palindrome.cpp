#include <iostream>
using namespace std;

int arrLength(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool CheckPalindrome(char arr[])
{
    int flag = true;
    int len = arrLength(arr);

    int p1 = 0;
    int p2 = len - 1;
    while (p1 <= p2)
    {
        if (arr[p1] != arr[p2])
        {
            return false;
        }
        p1++;
        p2--;
    }
    return true;
}

int main()
{
    char arr[100];
    cin >> arr;

    cout << CheckPalindrome(arr) << endl;

    return 0;
}