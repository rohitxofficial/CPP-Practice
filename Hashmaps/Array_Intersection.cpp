#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n1;
    cin >> n1;

    unordered_map<int, int> freq1;

    int *arr1 = new int[n1];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
        freq1[arr1[i]]++;
    }

    int n2;
    cin >> n2;

    unordered_map<int, int> freq2;

    int *arr2 = new int[n2];

    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
        freq2[arr2[i]]++;
    }

    for (int i = 0; i < n1; i++)
    {
        if (freq2.count(arr1[i]) > 0)
        {
            if (freq2[arr1[i]] > 0)
            {
                cout << arr1[i] << " ";
                freq1[arr1[i]]--;
                freq2[arr1[i]]--;
            }
        }
    }
    cout << endl;

    return 0;
}