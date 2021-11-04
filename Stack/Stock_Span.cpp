#include <iostream>
using namespace std;
#include <stack>

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> s;

    int *ans = new int[n]();

    for (int i = 0; i < n; i++)
    {
        while (s.empty() != true)
        {
            if (arr[s.top()] >= arr[i])
            {
                ans[i] = i - s.top();
                break;
            }
            else
            {
                s.pop();
            }
        }

        if (s.empty())
        {
            ans[i] = i + 1;
        }

        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}