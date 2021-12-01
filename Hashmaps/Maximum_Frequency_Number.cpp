#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> maxFreq;
    vector<int> unique;

    for (int i = 0; i < n; i++)
    {
        if (maxFreq.count(arr[i]) > 0)
            maxFreq[arr[i]]++;
        else
        {
            pair<int, int> temp = {arr[i], 1};
            maxFreq.insert(temp);
            unique.push_back(arr[i]);
        }
    }

    int max = INT_MIN;
    int maxElement;

    for (int i = 0; i < unique.size(); i++)
    {
        if (maxFreq[unique[i]] > max)
        {
            max = maxFreq[unique[i]];
            maxElement = unique[i];
        }
    }

    cout << maxElement << endl;

    return 0;
}