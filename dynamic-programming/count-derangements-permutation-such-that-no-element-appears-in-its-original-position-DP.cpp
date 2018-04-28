#include <iostream>

using namespace std; 

int derangements(int n) {
    int cache[n+1];
    cache[0] = 1;
    cache[1] = 0;
    cache[2] = 1;

    for (int i = 3; i <= n; i++)
        cache[i] = (i-1) * (cache[i-1] + cache[i-2]);

    return cache[n];
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n;

    cout << derangements(n);
}
