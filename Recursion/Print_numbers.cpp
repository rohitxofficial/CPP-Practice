/*Write a code to print numbers from 1 to n in increasing order recursively.*/

#include <iostream>
using namespace std;

void Print(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }

    Print(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;

    Print(n);

    return 0;
}