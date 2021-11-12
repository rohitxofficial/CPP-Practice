#include <iostream>
using namespace std;

bool checkAB(string s)
{
    if (s.length() == 0)
    {
        return true;
    }

    if (s[0] == 'a')
    {
        if (s.substr(1, 2) == "bb")
        {
            return checkAB(s.substr(1));
        }
        else if (s[1] == 'a')
        {
            return checkAB(s.substr(1));
        }
        else if (s.substr(1).empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (s.substr(0, 2) == "bb")
    {
        if (s[2] == 'a')
        {
            return checkAB(s.substr(2));
        }
        else if (s.substr(2).empty())
        {
            return true;
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
        if (checkAB(s))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    else
        cout << "false" << endl;

    return 0;
}
