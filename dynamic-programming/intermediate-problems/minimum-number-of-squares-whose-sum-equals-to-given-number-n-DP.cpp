#include <iostream>

using namespace std; 

int min(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

int squares(int n) {
    int cache[n+1];
    
    cache[0] = 0;
    cache[1] = 1; 
    cache[2] = 2;
    cache[3] = 3;

    for (int i = 4; i <= n; i++) {
        cache[i] = i;
        for (int j = 1; j <= i; j++) {
            if ((j * j) > i)
                break;
            else
                cache[i] = min(cache[i], 1 + cache[i-(j*j)]);
        }
    }

    return cache[n];
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n; 

    cout << squares(n);
}
