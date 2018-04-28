#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int xor_k(int *arr, int n, int k) {
    int max_ele = arr[0];
    for (int i = 0; i < n; i++) 
        if (max_ele < arr[i])
            max_ele = arr[i];

    int xor_max = (1 << (int)(log2(max_ele) + 1)) - 1;
    int cache[n+1][xor_max+1];
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++)
            cache[i][j] = 0;
    cache[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= xor_max; j++) {
            cache[i][j] = cache[i-1][j] + cache[i-1][j^arr[i-1]];
        }
    }

    return cache[n][k];
}

int main(int argc, char ** argv) {
    int n;
    cin>>n; 

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    int k;
    cin>>k;

    cout << xor_k(arr, n, k);
}
