#include <iostream>

using namespace std; 

int knapsack_1_0(int value[], int weight[], int W, int n) {
    
    int cache_value[n+1][W+1];

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < W+1; j++) {
            if (i == 0 || j == 0)
                cache_value[i][j] = 0;
            else if (W >= value[i-1])
                cache_value[i][j] = cache_value[i-1][j];
            else
                cache_value[i][j] = max(value[i-1] + cache_value[i-1][j-weight[i-1]], cache_value[i-1][j]);
        }
    }

    return cache_value[n][W];
}


int main(int argc, char ** argv) {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(value)/sizeof(value[0]);
    
    cout << knapsack_1_0(value, weight, W, n);
}
