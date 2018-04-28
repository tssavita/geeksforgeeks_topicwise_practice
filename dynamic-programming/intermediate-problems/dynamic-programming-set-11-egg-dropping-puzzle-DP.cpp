#include <iostream>
#include <climits>

using namespace std; 

int max(int a, int b) {
    return a < b ? a : b;
}

int egg_drop(int n, int k) {
    int eggs[n+1][k+1];

    for (int i = 1; i <= k; i++) {
        eggs[1][i] = k;
    }

    for (int i = 1; i <= n; i++) {
        eggs[i][0] = 0;
        eggs[i][1] = 1;
    }

    int res;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            eggs[i][j] = INT_MAX; 
            for (int x = 1; x <= j; x++) {
                res = 1 + max(eggs[i-1][x-1], eggs[i][j-x]);
                if (res < eggs[i][j])
                    eggs[i][j] = res; 
            }
        }
    }

    return eggs[n][k];
}

int main(int argc, char **argv) {
    int n, k;
    cin>>n>>k;

    cout << egg_drop(n, k);
}
