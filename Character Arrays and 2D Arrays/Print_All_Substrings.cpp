#include <iostream>
using namespace std;

void PrintAllSubstrings(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        for (int j = i; arr[j] != '\0'; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << endl;
        }
    }
}

int main()
{
    char arr[100];
    cin >> arr;

    PrintAllSubstrings(arr);

    return 0;
}