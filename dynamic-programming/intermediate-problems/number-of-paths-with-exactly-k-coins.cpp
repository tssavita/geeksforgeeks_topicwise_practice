#include <iostream>

using namespace std; 

int path_count(int **arr, int i, int j, int k) {
    if (i < 0 || j < 0)
        return 0;
    if (i == 0 && j == 0)
        return (k == arr[i][j]);

    return path_count(arr, i, j-1, k-arr[i][j]) +
           path_count(arr, i-1, j, k-arr[i][j]);
}

int path_count(int ** arr, int n, int k) {
    return path_count(arr, n-1, n-1, k);
}

int main(int argc, char ** argv) {
    int n, k;
    cin>>n>>k;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>arr[i][j];

    cout << path_count(arr, n, k);
}
