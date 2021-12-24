#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
int edit(string s1, string s2, int **output)
{
    int sizeS1 = s1.size();
    int sizeS2 = s2.size();

    if (sizeS1 == 0 || sizeS2 == 0)
        return max(sizeS1, sizeS2);

    if (output[sizeS1][sizeS2] != -1)
        return output[sizeS1][sizeS2];

    int ans;

    if (s1[0] == s2[0])
        ans = edit(s1.substr(1), s2.substr(1), output);
    else
    {
        // Delete
        int a = 1 + edit(s1.substr(1), s2, output);

        // Replace
        int b = 1 + edit(s1.substr(1), s2.substr(1), output);

        // Insert
        int c = 1 + edit(s1, s2.substr(1), output);

        ans = min(a, min(b, c));
    }

    output[sizeS1][sizeS2] = ans;

    return ans;
}

int editHelper(string s1, string s2)
{
    int sizeS1 = s1.size();
    int sizeS2 = s2.size();

    int **output = new int *[sizeS1 + 1];

    for (int i = 0; i <= sizeS1; i++)
    {
        output[i] = new int[sizeS2 + 1];
        for (int j = 0; j <= sizeS2; j++)
        {
            output[i][j] = -1;
        }
    }

    return edit(s1, s2, output);
}

// DYNAMIC PROGRAMMING
int editDP(string s1, string s2)
{
    int sizeS1 = s1.size();
    int sizeS2 = s2.size();

    int **output = new int *[sizeS1 + 1];

    for (int i = 0; i <= sizeS1; i++)
    {
        output[i] = new int[sizeS2 + 1];
        for (int j = 0; j <= sizeS2; j++)
        {
            if (i == 0)
                output[i][j] = j;
            if (j == 0)
                output[i][j] = i;
        }
    }

    for (int i = 1; i <= sizeS1; i++)
    {
        for (int j = 1; j <= sizeS2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                output[i][j] = output[i - 1][j - 1];
            else
            {
                // Delete
                int a = output[i - 1][j];

                // Replace
                int b = output[i - 1][j - 1];

                // Insert
                int c = output[i][j - 1];

                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }

    return output[sizeS1][sizeS2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << editDP(s1, s2) << endl;

    return 0;
}