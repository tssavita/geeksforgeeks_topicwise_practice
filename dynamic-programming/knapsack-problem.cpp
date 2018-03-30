#include <iostream>

using namespace std; 

int max(int a, int b) {
    return a ^ ((a ^ b) & (-(a < b)));
}

int knapsack(int W, int *weight, int *value, int n) {
    if (W == 0 || n == 0) 
        return 0;

    if (weight[n - 1] > W)
        return knapsack(W, weight, value, n - 1);

    return max(value[n - 1] + knapsack(W - weight[n - 1], weight, value, n - 1), knapsack(W, weight, value, n - 1));
}

int main(int argc, char **argv) {
    int n;
    cin>>n;

    int W;
    cin>>W;

    int *weight = new int[n];
    for (int i = 0; i < n; i++)
        cin>>weight[i];

    int *value = new int[n];
    for (int i = 0; i < n; i++)
        cin>>value[i];

    cout << knapsack(W, weight, value, n);
} 
