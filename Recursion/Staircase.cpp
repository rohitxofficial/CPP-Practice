#include <iostream>
using namespace std;

int Staircase(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int ans = 0;

    for (int i = 1; i <= 3; i++)
    {
        if (n - i >= 0)
            ans += Staircase(n - i);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << Staircase(n) << endl;

    return 0;
}
