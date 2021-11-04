#include <iostream>
using namespace std;
#include <stack>

int minimumBracketReversal(string exp)
{
    stack<char> s;

    int len = exp.length();

    if (len % 2 == 1)
    {
        return -1;
    }

    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '{')
        {
            s.push('{');
        }

        else
        {
            if (s.empty())
            {
                s.push('{');
                count++;
            }
            else
            {
                s.pop();
            }
        }
    }

    if (s.size() % 2 == 0)
    {
        return (s.size() / 2) + count;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string exp;
    cin >> exp;

    cout << minimumBracketReversal(exp) << endl;

    return 0;
}