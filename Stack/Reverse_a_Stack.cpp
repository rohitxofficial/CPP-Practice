#include <iostream>
using namespace std;
#include <stack>

void reverseStack(stack<int> &s1, stack<int> &s2, int len)
{
    if (len == 0)
    {
        return;
    }

    int temp = s2.top();
    s2.pop();

    reverseStack(s1, s2, len - 1);

    s1.push(temp);
}

int main()
{
    stack<int> s1;
    stack<int> s2;

    int len;
    cin >> len;

    for (int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;
        s1.push(temp);
    }

    for (int i = 0; i < len; i++)
    {
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
    }

    reverseStack(s1, s2, len);

    for (int i = 0; i < len; i++)
    {
        cout << s1.top() << endl;
        s1.pop();
    }

    return 0;
}