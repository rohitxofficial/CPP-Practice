#include <iostream>
using namespace std;

bool isPartOfFibonacci(int n)
{
    int a = 0;
    int b = 1;
    bool flag = false;
    while (a <= n)
    {
        int temp = a + b;
        a = b;
        b = temp;
        if (a == n)
        {
            flag = true;
        }
    }
    return flag;
}

int main()
{
    int n;
    cin >> n;
    if (isPartOfFibonacci(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}