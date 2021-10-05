#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum_array = 0;

    for (int i = 0; i < n; i++)
    {
        sum_array += arr[i];
    }

    int sum = ((n - 2) * (n - 1)) / 2;

    cout << sum_array - sum << endl;

    return 0;
}
