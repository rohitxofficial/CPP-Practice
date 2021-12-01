#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, bool> status;

    for (char i : s)
    {
        status[i] = true;
    }

    for (char i : s)
    {
        if (status[i] == true)
        {
            cout << i;
            status[i] = false;
        }
    }
    cout << endl;

    return 0;
}