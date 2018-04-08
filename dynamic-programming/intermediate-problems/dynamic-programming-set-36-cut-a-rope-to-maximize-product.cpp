#include <iostream>

using namespace std; 

int max(int a, int b) {
    return (a < b) ? b : a;
}

int max(int a, int b, int c) {
    return (max(a, b) < c) ? c : max(a, b);
}

int max_product(int n) {
    if (n == 0 || n == 1)
        return 0;

    int product = 0; 

    for (int i = 1; i < n; i++) 
        product = max(product, i * (n-i), i * max_product(n-i));

    return product; 
}

int main(int argc, char **argv) {
    int n;
    cin>>n; 

    cout << max_product(n);
}
