#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<char> s;

    int lenStr = str.length();

    for (int i = 0; i < lenStr; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else
        {
            if (s.empty())
            {
                cout << "false" << endl;
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }

    if (s.empty())
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}