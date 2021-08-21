#include <iostream>
using namespace std;

bool CheckAB(string s)
{
    if (s.empty())
    {
        return true;
    }

    if (s[0] == 'a')
    {
        if (s[1] == 'a')
        {
            return CheckAB(s.substr(1));
        }
        else if (s.substr(1, 2) == "bb")
        {
            return CheckAB(s.substr(1));
        }
        else
        {
            return false;
        }
    }

    else if (s.substr(0, 2) == "bb")
    {
        if (s.substr(2).empty())
        {
            return CheckAB(s.substr(2));
        }
        else if (s[2] == 'a')
        {
            return CheckAB(s.substr(2));
        }
        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}

int main()
{
    string s;
    cin >> s;

    if (s[0] == 'a')
    {
        cout << CheckAB(s) << endl;
    }
    else
    {
        cout << false << endl;
    }

    return 0;
}