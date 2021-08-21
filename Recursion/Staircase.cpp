#include <iostream>
using namespace std;

int output = 0;

void Staircase(int n)
{
    if (n == 0)
    {
        output++;
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (n - i >= 0)
            Staircase(n - i);
    }
}

int main()
{
    int n;
    cin >> n;

    Staircase(n);

    cout << output << endl;

    return 0;
}