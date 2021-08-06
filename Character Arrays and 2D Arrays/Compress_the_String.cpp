/*
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive
duplicate occurrences with the count of repetitions.
*/

#include <iostream>
using namespace std;

void Compress(char arr[])
{
    int p1 = 0;
    int p2 = 0;
    while (true)
    {
        int count = 0;
        arr[p1] = arr[p2];
        while (arr[p2] == arr[p1])
        {
            count++;
            p2++;
        }

        if (count > 1)
        {
            arr[p1] = arr[p2 - 1];
            arr[p1 + 1] = (char)count + 48;
            p1 += 2;
        }
        else
        {
            arr[p1] = arr[p2 - 1];
            p1++;
        }

        if (arr[p2] == '\0')
        {
            arr[p1] = '\0';
            break;
        }
    }
    cout << arr;
}

int main()
{
    char arr[100];
    cin >> arr;

    Compress(arr);

    return 0;
}