#include <iostream>

using namespace std; 

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int max_profit(int *arr, int n) {
    int cache[n][n];

    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++)  {
            int x = ((i + 2) <= j) ? cache[i+2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? cache[i+1][j-1] : 0;
            int z = ( i <= (j - 2)) ? cache[i][j-2] : 0;

            cache[i][j] = max((arr[i] + min(x, y)), (arr[j] + min(y,z)));
        }
    }
    return cache[0][n-1];
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    cout << max_profit(arr, n);
}
