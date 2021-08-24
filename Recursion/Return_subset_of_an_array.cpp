#include <iostream>
#include <math.h>
using namespace std;

void CreateJaggedArray(int **output, int n)
{
    if (n == 0)
    {
        output[0] = new int[1];
        output[0][0] = 0;
        return;
    }

    CreateJaggedArray(output, n - 1);

    int maxrange = pow(2, n);

    for (int i = maxrange / 2; i < maxrange; i++)
    {
        output[i] = new int[output[i - (maxrange / 2)][0] + 1];
        output[i][0] = output[i - (maxrange / 2)][0] + 1;
    }
}

void ReturnSubset(int st, int n, int arr[], int **output)
{
    if (n == 1)
    {
        output[1][1] = arr[st];
        return;
    }

    ReturnSubset(st + 1, n - 1, arr, output);

    int maxrange = pow(2, n);

    for (int i = maxrange / 2; i < maxrange; i++)
    {
        output[i][1] = arr[st];
        for (int j = 2; j <= output[i][0]; j++)
        {
            output[i][j] = output[i - (maxrange / 2)][j - 1];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int len = 1;

    for (int i = 0; i < n; i++)
    {
        len *= 2;
    }

    int **output = new int *[len];

    CreateJaggedArray(output, n);

    ReturnSubset(0, n, arr, output);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < output[i][0]; j++)
        {
            cout << output[i][j + 1] << " ";
        }
        cout << endl;
    }

    delete arr;
    for (int i = 0; i < len; i++)
    {
        delete output[i];
    }
    delete output;

    return 0;
}