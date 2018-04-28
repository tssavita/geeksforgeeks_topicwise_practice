#include <iostream>
#include <cstring> 

using namespace std; 

#define n 6

int max(int a, int b) {
    return a > b ? a : b;
}

int collect_coins(char **arr, int i, int j, int dir, int dp[n][n][2]) {
    if (i <= 0 || j <= 0 || i > n || j > n || arr[i][j] == '#') 
        return 0;

    if (dp[i][j][dir] != -1)
        return dp[i][j][dir];

    dp[i][j][dir] = (arr[i][j] == 'C') ? 1 : 0;
    
    if (dir == 1) 
        dp[i][j][dir] += max(collect_coins(arr, i+1, j, 0, dp), collect_coins(arr, i, j+1, 1, dp));
    
    dp[i][j][dir] += max(collect_coins(arr, i+1, j, 0, 1, dp), collect_coins(arr, i, j-1, 0, dp));
    return dp[i][j][dir];
}

int collect_coins(char ** arr) {
    int cache[n][n][2];
    
    memset(cache, -1, sizeof(cache));

    return collect_coins(arr, 0, 0, 1, cache);
}

int main(int argc, char ** argv) {

    char **arr = new char*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new char[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>arr[i][j];
    }

    cout << collect_coins(arr);
}
