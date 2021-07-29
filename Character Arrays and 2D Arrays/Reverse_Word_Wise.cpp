/*
Reverse the given string word wise. That is, the last word 
in given string should come at 1st place, last second word 
at 2nd place and so on. Individual words should remain as it is.
*/

#include <iostream>
using namespace std;

int length(char arr[])
{
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void ReverseWordWise(char arr[], int len)
{
    int p1 = 0;
    int p2 = p1;

    while (p1 < len)
    {
        int p2_max = 0;
        while (arr[p2] != ' ' && arr[p2] != '\0')
        {
            p2++;
        }
        p2 -= 1;
        p2_max = p2;

        while (p1 < p2)
        {
            int temp = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = temp;
            p1++;
            p2--;
        }

        p1 = p2_max + 2;
        p2 = p1;
    }

    int p1_f = 0;
    int p2_f = len - 1;
    while (p1_f < p2_f)
    {
        int temp = arr[p1_f];
        arr[p1_f] = arr[p2_f];
        arr[p2_f] = temp;
        p1_f++;
        p2_f--;
    }
}

int main()
{
    char arr[100];
    cin.getline(arr, 100);

    int len = length(arr);
    ReverseWordWise(arr, len);

    cout << arr;

    return 0;
}