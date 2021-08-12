#include <iostream>
using namespace std;

int SumofDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = SumofDigits(n / 10);

    return (n % 10) + ans;
}

int main()
{
    int n;
    cin >> n;

    cout << SumofDigits(n) << endl;

    return 0;
}