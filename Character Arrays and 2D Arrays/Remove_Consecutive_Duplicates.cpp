/*
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbccaa"
Expected Output: "abca"
*/

#include <iostream>
using namespace std;

int main()
{
    char arr[100];
    cin >> arr;

    int p1 = 1;
    int p2 = 1;
    char curr = arr[0];
    while (true)
    {
        if (arr[p2] != curr)
        {
            arr[p1] = arr[p2];
            curr = arr[p2];
            p1++;
        }
        if (arr[p2] == '\0')
        {
            break;
        }
        p2++;
    }

    cout << arr;

    return 0;
}