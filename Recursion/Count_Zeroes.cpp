#include <iostream>
using namespace std;

int CountZeroes(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n <= 9)
    {
        return 0;
    }

    if (n % 10 == 0)
    {
        return 1 + CountZeroes(n / 10);
    }

    return CountZeroes(n / 10);
}

int main()
{
    int n;
    cin >> n;

    cout << CountZeroes(n) << endl;

    return 0;
}