/*
Given an input string S that contains multiple words,
you need to remove all the spaces present in the input
string.
*/

#include <iostream>
using namespace std;

void Trim(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ' ')
        {
            for (int j = i; arr[j] != '\0'; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
}

int main()
{
    char arr[100];
    cin.getline(arr, 100);

    Trim(arr);

    cout << arr;

    return 0;
}