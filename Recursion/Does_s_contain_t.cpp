#include <iostream>
using namespace std;

bool TinS(string s, string t)
{
    if (t.empty())
    {
        return true;
    }
    if (s.empty())
    {
        return false;
    }

    if (t[0] == s[0])
    {
        return TinS(s.substr(1), t.substr(1));
    }
    else
    {
        return TinS(s.substr(1), t);
    }
}

int main()
{
    string s, t;
    cin >> s >> t;

    if (TinS(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}