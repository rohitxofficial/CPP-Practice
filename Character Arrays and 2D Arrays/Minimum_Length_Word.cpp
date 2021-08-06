/*
Given a string S (that can contain multiple words), 
you need to find the word which has minimum length.
*/

#include <iostream>
#include <climits>
using namespace std;

void MinimumLengthWord(char arr[])
{
    int min_index = 0;

    int p1 = 0;
    int counter = INT_MAX;
    while (true)
    {
        int counter_temp = 0;
        while (arr[p1] != ' ' && arr[p1] != '\0')
        {
            counter_temp++;
            p1++;
        }

        if (counter_temp < counter)
        {
            counter = counter_temp;
            min_index = p1 - 1;
        }

        if (arr[p1] == '\0')
        {
            break;
        }

        p1++;
    }

    int p2;
    int p3 = min_index;
    while (arr[min_index] != ' ' && min_index != -1)
    {
        min_index--;
    }
    p2 = min_index + 1;

    for (int i = p2; i <= p3; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    char arr[100];
    cin.getline(arr, 100);

    MinimumLengthWord(arr);

    return 0;
}