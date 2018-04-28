#include <iostream>

using namespace std; 

int max(int a, int b) {
    return (a < b) ? b : a;
}

int max(int a, int b, int c) {
    return (max(a, b) < c) ? c : max(a, b);
}

int max_product(int n) {
    int cache[n+1];

    cache[0] = 0;
    cache[1] = 0;

    for (int i = 1; i <= n; i++) {
        int product = 0;   
        for (int j = 1; j <= i/2; j++)
            product = max(product, j * (i - j), j * cache[i - j]);
        cache[i] = product; 
    }

    return cache[n];
}

int main(int argc, char **argv) {
    int n;
    cin>>n;

    cout << max_product(n);
}
