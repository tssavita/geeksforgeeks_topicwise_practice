#include <iostream>

using namespace std;

int max_product(int n) {
    if (n <= 3)
        return n-1;
    int res = 1; 
    while (n > 4) {
        n -= 3;
        res *= 3; 
    }

    return res * n; 
}

int main(int argc, char **argv) {
    int n; 
    cin>>n;

    cout << max_product(n);
}
