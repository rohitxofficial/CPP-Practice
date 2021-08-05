/*
Given two strings, 'str1' and 'str2', check whether they are 
a permutation of each other or not.
*/

#include <iostream>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];

    cin >> str1;
    cin >> str2;

    int arr[128] = {0};

    int i = 0;
    while (str1[i] != '\0')
    {
        arr[str1[i]]++;
        arr[str2[i]]++;
        i++;
    }

    bool flag = true;
    for (int i = 0; i < 128; i++)
    {
        if (arr[i] % 2 == 1)
        {
            flag = false;
            break;
        }
    }

    cout << flag << endl;

    return 0;
}