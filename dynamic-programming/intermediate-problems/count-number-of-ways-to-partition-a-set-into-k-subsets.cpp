#include <iostream>

using namespace std; 

int sterling(int n, int k) {
    if (n == 0 || k == 0 || n < k)
        return 0;
    if (k == 1 || k == n) 
        return 1; 

    return k * sterling(n - 1, k) + sterling(n - 1, k - 1);
}

int main(int argc, char **argv) {
    int n, k;
    cin>>n>>k; 
    cout << sterling(n, k);
}
