#include <iostream>
#include <climits>

using namespace std;

int min(int a, int b, int c) {
    return (a < b) ? ((a < c)? a : c) : ((b < c)? b : c);
}

int min_cost(int m, int n, int cost_matrix[3][3]) {
    int cache_cost[m][n];
    cache_cost[0][0] = cost_matrix[0][0];
    
    for (int i = 1; i <= m; i++)
        cache_cost[i][0] = cache_cost[i-1][0] + cost_matrix[i][0];
    
    for (int i = 1; i <= n; i++)
        cache_cost[0][i] = cache_cost[0][i-1] + cost_matrix[0][i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cache_cost[i][j] = cost_matrix[i][j] + min(cache_cost[i-1][j],
                                            cache_cost[i-1][j-1],
                                            cache_cost[i][j-1]);
        }
    }
    return cache_cost[m][n];
}

int main(int argc, char ** argv) {
    int cost_matrix[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    cout << min_cost(2, 2, cost_matrix);
}
