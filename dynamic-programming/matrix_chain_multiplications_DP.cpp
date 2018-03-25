#include <iostream>
#include <climits>

using namespace std;

int matrix_multiplication_minop(int arr[], int n) {
    int cache_opnum[n][n];

    for (int i = 0; i < n; i++)
        cache_opnum[i][i] = 0;

    for (int i = 2; i < n; i++) {
        for (int start = 1; start < (n - i + 1); start++) {
            int end = i + start - 1;
            cache_opnum[start][end] = INT_MAX;
            for (int k = start; k < end; k++) {
                int count = cache_opnum[start][k] + cache_opnum[k+1][end] + arr[start-1]*arr[k]*arr[end];
                if (count < cache_opnum[start][end])
                    cache_opnum[start][end] = count; 
            }
        }
    } 
    return cache_opnum[1][n-1];
}

int main(int argc, char ** argv) {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << matrix_multiplication_minop(arr, n);
}
