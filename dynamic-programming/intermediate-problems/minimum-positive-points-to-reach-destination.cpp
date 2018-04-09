#include <iostream>
#include <cstdlib>

using namespace std; 

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int points_at_end(int ** arr, int n) {
    int d[n][n];

    d[n-1][n-1] = arr[n-1][n-1] > 0 ? 1 : abs(arr[n-1][n-1]) + 1;
    for (int i = n-2; i >= 0; i--)
        d[i][n-1] = max(d[i+1][n-1] - arr[i][n-1], 1);
    for (int j = n-2; j >= 0; j--)
        d[n-1][j] = max(d[n-1][j+1] - arr[n-1][j], 1);

    for (int i = n-2; i >= 0; i--) {
        for (int j = n-2; j >= 0; j--) {
            int min_exit = min(d[i+1][j], d[i][j+1]);
            d[i][j] = max(min_exit - arr[i][j], 1);
        }
    }

    return d[0][0];
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int ** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin>>arr[i][j];

    cout << points_at_end(arr, n);
}
