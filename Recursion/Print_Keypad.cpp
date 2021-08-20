#include <iostream>
using namespace std;

void PrintKeypad(int n, string output, string keypad[])
{
    if (n == 0)
    {
        cout << output << endl;
        return;
    }

    int digit = n % 10;
    for (int i = 0; i < keypad[digit].size(); i++)
    {
        PrintKeypad(n / 10, keypad[digit][i] + output, keypad);
    }
}

int main()
{
    int n;
    cin >> n;

    string keypad[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    PrintKeypad(n, "", keypad);

    return 0;
}