#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int binomial_coefficient(int n, int k) {
    int coefficients[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                coefficients[i][j] = 1;
            else
                coefficients[i][j] = coefficients[i-1][j-1] + coefficients[i-1][j];
        }
    }
    return coefficients[n][k];
}

int main(int argc, char ** argv) { 
    int n, k;
    cin>>n>>k;
    cout << binomial_coefficient(n, k);
}
