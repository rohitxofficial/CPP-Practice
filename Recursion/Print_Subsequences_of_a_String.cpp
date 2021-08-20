#include <iostream>
using namespace std;

void PrintSubsequences(string s, string output)
{
    if (s.empty())
    {
        cout << output << endl;
        return;
    }

    PrintSubsequences(s.substr(1), output);
    PrintSubsequences(s.substr(1), output + s[0]);
}

int main()
{
    string s;
    cin >> s;

    PrintSubsequences(s, "");

    return 0;
}