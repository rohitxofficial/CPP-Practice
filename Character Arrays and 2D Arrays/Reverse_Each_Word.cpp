/*
Input Sentence: "Hello World"
The expected output will print, "olleH dlroW".
*/

#include <iostream>
using namespace std;

int main()
{
    char arr[100];
    cin.getline(arr, 100);

    int p1 = 0;
    int p2 = 0;
    while (true)
    {
        while (arr[p2] != ' ' && arr[p2] != '\0')
        {
            p2++;
        }

        int p2_max = p2 - 1;

        while (p1 < p2_max)
        {
            char temp = arr[p1];
            arr[p1] = arr[p2_max];
            arr[p2_max] = temp;
            p1++;
            p2_max--;
        }

        if (arr[p2] == '\0')
        {
            break;
        }

        p2 += 1;
        p1 = p2;
    }

    cout << arr;

    return 0;
}