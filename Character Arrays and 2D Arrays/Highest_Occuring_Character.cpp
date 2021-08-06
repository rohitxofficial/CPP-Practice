/*
Given a string(str), find and return the highest occurring character.
*/

#include <iostream>
using namespace std;

int main()
{
    char arr[100];
    cin >> arr;

    int count[128] = {0};

    int i = 0;
    int max = 0;
    int max_index = 0;
    while (arr[i] != '\0')
    {
        count[arr[i]]++;
        if (count[arr[i]] > max)
        {
            max = count[arr[i]];
            max_index = arr[i];
        }
        i++;
    }

    cout << (char)max_index << endl;

    return 0;
}