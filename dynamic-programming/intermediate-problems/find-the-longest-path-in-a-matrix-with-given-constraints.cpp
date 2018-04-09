#include <iostream>
#include <cstring>

using namespace std;

#define n 3

int longest_path(int **arr, int cache[n][n], int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n)
        return 0;

    if (cache[i][j] != -1)
        return cache[i][j];
    
    int result; 
    if (i < n-1 && (arr[i][j] + 1) == arr[i+1][j]) {
        cache[i][j] = longest_path(arr, cache, i+1, j) + 1;
        return cache[i][j];
    }
    if (j < n-1 && (arr[i][j] + 1) == arr[i][j+1]) {
        cache[i][j] = longest_path(arr, cache, i, j+1) + 1;
        return cache[i][j];
    }
    if (i > 0 && ((arr[i][j] + 1) == arr[i-1][j])) {
        cache[i][j] = longest_path(arr, cache, i-1, j) + 1;
        return cache[i][j];
    }
    if (j > 0 && ((arr[i][j] + 1) == arr[i][j-1])) {
        cache[i][j] = longest_path(arr, cache, i, j-1) + 1;
        return cache[i][j];
    }
    cache[i][j] = 1;
    return cache[i][j];
}

int longest_path(int **arr) {
    int cache[n][n];

    memset(cache, -1, sizeof(cache));

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cache[i][j] == -1)
                longest_path(arr, cache, i, j);
            result = max(result, cache[i][j]);
        }
    }

    return result;
}

int main(int argc, char ** argv) {
    
    int **arr = new int*[n];
    for (int i = 0; i <n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin>>arr[i][j];

    cout << longest_path(arr);
}
