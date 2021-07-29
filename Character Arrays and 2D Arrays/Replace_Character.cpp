/*
Given and input string S and two characters c1 and c2,
you need to replace every occurrence of character c1
with character c2 in the given string.
*/

#include <iostream>
using namespace std;

int main()
{
    char arr[100];

    cin >> arr;

    char c1, c2;
    cin >> c1 >> c2;

    int i = 0;
    while (arr[i] != '\0')
    {
        if (arr[i] == c1)
        {
            arr[i] = c2;
        }
        i++;
    }

    cout << arr;

    return 0;
}