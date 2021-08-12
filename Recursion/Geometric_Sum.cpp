/*
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
*/

#include <iostream>
using namespace std;

int power(int n)
{
    if (n == 1)
    {
        return 2;
    }

    return 2 * power(n - 1);
}

double GeometricSum(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return (1.0 / power(n)) + GeometricSum(n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << GeometricSum(n) << endl;

    return 0;
}