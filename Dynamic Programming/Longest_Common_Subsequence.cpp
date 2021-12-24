#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int lcs(string s1, string s2, int **output)
{
    int m = s1.size();
    int n = s2.size();

    if (m == 0 || n == 0)
        return 0;

    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;

    if (s1[0] == s2[0])
    {
        ans = 1 + lcs(s1.substr(1), s2.substr(1), output);
    }
    else
    {
        int a = lcs(s1, s2.substr(1), output);
        int b = lcs(s1.substr(1), s2, output);

        ans = max(a, b);
    }

    output[m][n] = ans;

    return ans;
}

int lcsHelper(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int **output = new int *[m + 1];

    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return lcs(s1, s2, output);
}

// DYNAMIC PROGRAMMING
int lcsDP(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int **output = new int *[m + 1];

    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                output[i][j] = output[i - 1][j - 1] + 1;
            else
                output[i][j] = max(output[i][j - 1], output[i - 1][j]);
        }
    }

    return output[m][n];
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;

    cout << lcsDP(s1, s2) << endl;

    return 0;
}