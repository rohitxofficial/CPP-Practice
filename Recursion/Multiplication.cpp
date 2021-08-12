#include <iostream>
using namespace std;

int Multiply(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }

    int sum = m + Multiply(m, n - 1);

    return sum;
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << Multiply(m, n) << endl;

    return 0;
}