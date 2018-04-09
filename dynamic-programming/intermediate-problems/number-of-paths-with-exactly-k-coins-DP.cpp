#include <iostream>
#include <cstring>

using namespace std; 

int cache[5][5][1000];

int ksum_paths(int **arr, int n, int i, int j, int k) {
    if (i < 0 || j < 0)
        return 0;
    if (i == 0 && j == 0)
        return (arr[i][j] == k);
    if (cache[i][j][k] != -1)
        return cache[i][j][k];

    cache[i][j][k] = ksum_paths(arr, n, i-1, j, k-arr[i][j]) + ksum_paths(arr, n, i, j-1, k-arr[i][j]);

    return cache[n][n][k];
}

int ksum_paths(int ** arr, int n, int k) {
    memset(cache, -1, sizeof(cache));

    return ksum_paths(arr, n, n-1, n-1, k);
}

int main(int argc, char ** argv) {
    int n, k;
    cin>>n>>k;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>arr[i][j];
    }

    cout << ksum_paths(arr, n, k);
}
