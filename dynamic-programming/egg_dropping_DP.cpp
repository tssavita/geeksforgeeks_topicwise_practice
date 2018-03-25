#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

int eggdroppingtrials(int eggs, int floors) {
    int cache_trials[eggs+1][floors+1];

    for (int i = 1; i <= floors; i++) {
        cache_trials[1][i] = i;
    }

    for (int i = 1; i <= eggs; i++) {
        cache_trials[i][1] = 1;
        cache_trials[i][0] = 1;
    }

    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            cache_trials[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++) {
                int res = 1 + max(cache_trials[i-1][x-1], cache_trials[i][j-x]);
                if (cache_trials[i][j] > res)
                    cache_trials[i][j] = res; 
            }
            cout <<  i << " " << j << " " << cache_trials[i][j] << endl;
        }
    }
    return cache_trials[eggs][floors];
}

int main(int argc, char ** argv) {
    int eggs;
    cin>>eggs;

    int floors;
    cin>>floors;

    cout << eggdroppingtrials(eggs, floors);
}
