#include <iostream>

using namespace std; 

int square_limit(int n) {
    if (n <= 3)
        return n;
    int sum = n;
    for (int i = 1; i < n; i++) {
        if (i * i > n)
            break;
        sum = min(sum, 1 + square_limit(n-(i*i)));
    }

    return sum;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    cout << square_limit(n);
}
