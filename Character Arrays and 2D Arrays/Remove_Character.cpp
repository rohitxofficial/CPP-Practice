/*
For a given a string(str) and a character X, write a function to remove all the occurrences of X from the given string.
The input string will remain unchanged if the given character(X) doesn't exist in the input string.
*/

#include <iostream>
using namespace std;

int main()
{
    char arr[100];
    cin >> arr;

    char del;
    cin >> del;

    int p1 = 0;
    int p2 = 0;

    while (true)
    {
        if (arr[p2] != del)
        {
            arr[p1] = arr[p2];
            p1++;
            p2++;
        }
        else
        {
            p2++;
        }

        if (arr[p2] == '\0')
        {
            arr[p1] = '\0';
            break;
        }
    }

    cout << arr << endl;

    return 0;
}