#include <iostream>
using namespace std;

int FahrenheitToCelsius(int n)
{
    return (5.0 / 9) * (n - 32);
}

int main()
{
    int s, e, w;
    cin >> s >> e >> w;

    for (int i = s; i <= e; i += w)
    {
        cout << i << " " << FahrenheitToCelsius(i) << endl;
    }

    return 0;
}