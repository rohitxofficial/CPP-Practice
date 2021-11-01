#include <iostream>
using namespace std;
#include <queue>

void reverseQueue(queue<int> &q, int len)
{
    if (len == 0)
    {
        return;
    }

    int temp = q.front();
    q.pop();

    reverseQueue(q, len - 1);

    q.push(temp);
}

int main()
{
    int len;
    cin >> len;

    queue<int> q;

    for (int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }

    reverseQueue(q, len);

    for (int i = 0; i < len; i++)
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}