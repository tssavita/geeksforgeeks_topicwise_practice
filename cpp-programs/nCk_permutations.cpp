#include<iostream>

using namespace std; 

long choose(long int n, long int k) {
    if (k > n)
        return 0;
    long r = 1;
    for (long d = 1; d <= k; d++) {
        r *= n--;
        r /= d; 
    }
    return r;
}

int main(int argc, char ** argv) {
    long n;
    cin>>n;
    long k;
    cin>>k;

    cout << choose(n,k);
    return 0;
}
