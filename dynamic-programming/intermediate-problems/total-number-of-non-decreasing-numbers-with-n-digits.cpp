#include <iostream>
#include <cstring>

using namespace std; 

int count_nondecreasing(int n) {
    int cache[10][n+1];

    memset(cache, 0, sizeof(cache));

    for (int i = 0; i <= 9; i++) 
        cache[i][1] = 1;
    
    for (int d = 0; d <= 9; d++) {
        for (int l = 2; l <= n; l++) {
            for (int x = 0; x <= d; x++)
                cache[d][l] += cache[x][l-1];
        }
    }

    long long int result = 0;
    for (int i = 0; i <= 9; i++)
        result += cache[i][n];

    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n; 

    cout << count_nondecreasing(n);
}
