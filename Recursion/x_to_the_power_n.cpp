/*
Write a program to find x to the power n (i.e. x^n). 
Take x and n from the user. You need to return the answer.
*/

#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * (power(x, n - 1));
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;

    return 0;
}