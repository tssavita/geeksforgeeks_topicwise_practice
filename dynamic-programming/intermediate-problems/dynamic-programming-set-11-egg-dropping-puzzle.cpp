#include <iostream>
#include <climits>

using namespace std; 

int egg_drop(int n, int k) {
    if (k == 0 || k == 1 || n == 1)
        return k;
    
    int min = INT_MAX, res;
    for (int x = 1; x <= k; x++) {
        res = max(egg_drop(n-1, x-1), egg_drop(n, k-x));
        if (res < min)
            min = res;
    }

    return min + 1; 
}

int main(int argc, char **argv) {
    int n, k;
    cin>>n>>k;

    cout << egg_drop(n, k);
}
