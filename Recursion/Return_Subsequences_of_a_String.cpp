#include <iostream>
using namespace std;

int ReturnSubsequences(string s, string output[])
{
    if (s.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = s.substr(1);
    int n = ReturnSubsequences(smallString, output);

    for (int i = 0; i < n; i++)
    {
        output[n + i] = s[0] + output[i];
    }

    return 2 * n;
}

int main()
{
    string s;
    cin >> s;

    int len = s.size();

    int arr_len = 2;
    for (int i = 1; i < len; i++)
    {
        arr_len *= 2;
    }

    string *output = new string[arr_len];

    int n = ReturnSubsequences(s, output);

    for (int i = 0; i < arr_len; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}