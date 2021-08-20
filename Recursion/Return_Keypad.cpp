#include <iostream>
using namespace std;

void ReturnKeypad(int n, int len, string arr[], string output[])
{
    if (n == 0)
    {
        output[0] = "";
        return;
    }

    int digit = n % 10;
    int smallLen = len / arr[digit].size();
    ReturnKeypad(n / 10, smallLen, arr, output);

    string temp[smallLen];
    for (int i = 0; i < smallLen; i++)
    {
        temp[i] = output[i];
    }

    for (int i = 0; i < arr[digit].size(); i++)
    {
        for (int j = 0; j < smallLen; j++)
        {
            output[j + (i * smallLen)] = temp[j] + arr[digit][i];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int len = 1;
    for (int i = n; i > 0; i /= 10)
    {
        if (i % 10 == 7 || i % 10 == 9)
        {
            len *= 4;
        }
        else if (i % 10 == 1 || i % 10 == 0)
        {
            len *= 1;
        }
        else
        {
            len *= 3;
        }
    }

    string *output = new string[len];

    string arr[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    ReturnKeypad(n, len, arr, output);

    for (int i = 0; i < len; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}