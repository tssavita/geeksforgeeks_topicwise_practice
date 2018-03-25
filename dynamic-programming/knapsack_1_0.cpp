#include <iostream>

using namespace std;

int knapsack_1_0(int value[], int weight[], int W, int n) {
    if (W == 0 || n == 0) 
        return 0;

    if (weight[n-1] > W)
        return knapsack_1_0(value, weight, W, n-1);

    return max((value[n-1] + knapsack_1_0(value, weight, W-weight[n-1], n-1)), knapsack_1_0(value, weight, W, n-1));
}

int main(int argc, char ** argv) {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(value)/sizeof(value[0]);
    
    cout << knapsack_1_0(value, weight, W, n);
}
