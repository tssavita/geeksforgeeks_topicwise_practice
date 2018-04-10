#include <iostream>
#include <cstring>

using namespace std; 

#define M 3
#define N 3 
#define K 2
#define D 2

int count_paths(int m, int n, int k, int d, int cache[M][N][K][D]) {
    if (m < 0 || n < 0)
        return 0;
    if (m == 0 && n == 0)
        return 1;
    if (k == 0) {
        if (d == 0 && m == 0)
            return 0; 
        if (d == 1 && n == 0)
            return 1; 
    }
    if (cache[m][n][k][d] != -1)
        return cache[m][n][k][d];
    if (d == 0)
        cache[m][n][k][d] = count_paths(m, n-1, k, d, cache) + count_paths(m-1, n, k-1, !d, cache);
    else 
        cache[m][n][k][d] = count_paths(m-1, n, k, d, cache) + count_paths(m, n-1, k-1, !d, cache);

    return cache[m][n][k][d];
}

int count_paths(int m, int n, int k) {
    int cache[M][N][K][2];
    if (m == 0 && n == 0)
        return 1;

    memset(cache, -1, sizeof(cache));

    return count_paths(m-1, n, k, 1, cache) + count_paths(m, n-1, k, 0, cache);
}

int main(int argc, char ** argv) {
    int m, n, k;
    cin>>m>>n>>k;

    cout << count_paths(m-1, n-1, k);
}
