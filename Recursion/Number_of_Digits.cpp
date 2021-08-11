#include <iostream>
using namespace std;

int CountDigits(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return 1 + CountDigits(n / 10);
}

int main()
{
    int n;
    cin >> n;

    cout << CountDigits(n) << endl;

    return 0;
}