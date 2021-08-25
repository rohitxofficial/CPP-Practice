#include <iostream>
using namespace std;

void PrintSubsets(int arr[], int n, int output[], int m) {
    if (n == 0) {
        for (int i = 0; i < m; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    
    PrintSubsets(arr + 1, n - 1, output, m);
    output[m] = arr[0];
    PrintSubsets(arr + 1, n - 1, output, m + 1);
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int* output = new int[n];

    PrintSubsets(arr, n, output, 0);

    delete arr;
    delete output;

    return 0;
}