#include <iostream>
using namespace std;
#include <stack>

int main()
{
    string exp;
    cin >> exp;

    stack<char> s;

    bool ans = false;

    int len = exp.length();
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == ')')
        {
            int count = 0;
            while (s.top() != '(')
            {
                s.pop();
                count++;
            }
            if (count < 2)
            {
                ans = true;
                break;
            }
            s.pop();
            s.push(' ');
        }
        else
        {
            s.push(exp[i]);
        }
    }

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}