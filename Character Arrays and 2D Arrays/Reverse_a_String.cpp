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

void Reverse(char arr[], int n)
{
    int p1 = 0;
    int p2 = n - 1;
    while (p1 <= p2)
    {
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
        p1++;
        p2--;
    }
}

int main()
{
    char arr[100];
    cin.getline(arr, 100);

    int len = length(arr);

    Reverse(arr, len);

    cout << arr;

    return 0;
}