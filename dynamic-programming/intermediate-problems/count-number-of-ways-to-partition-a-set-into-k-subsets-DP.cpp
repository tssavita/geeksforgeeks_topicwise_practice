#include <iostream>

using namespace std;

int partitions(int n, int k) {
    int dp[n + 1][k + 1];
    for (int i = 0; i < n; i++) 
        dp[0][k] = 0;
    
    for (int j = 0; j < k; j++) 
        dp[j][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ( j == 1 || i == j)
                dp[i][j] = 1; 
            else 
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    return dp[n][k];
}

int main(int argc, char ** argv) {
    int n, k;
    cin>>n>>k;

    cout << partitions(n, k);
}
