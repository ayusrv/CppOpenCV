#include<bits/stdc++.h>
using namespace std;
void add(int arr1[][3], int arr2[][3], int n, int m) {
    int sum[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    // Print the sum matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    int m = 3;
    int arr1[n][m];
    int arr2[n][m];

    // Input for first array
    cout << "Enter elements of first array:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr1[i][j];
        }
    }

    // Input for second array
    cout << "Enter elements of second array:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr2[i][j];
        }
    }

    // Call the function to add the matrices
    cout << "Resultant array:" << endl;
    add(arr1, arr2, n, m);

    return 0;
}