#include <iostream>
#include <climits>

using namespace std;

int min_diff(int *arr, int n) {
    int totalsum = 0;
    for (int i = 0; i < n; i++)
        totalsum += arr[i];

    bool cache[n+1][totalsum+1];
    for (int i = 0; i <= n; i++)
        cache[i][0] = true;

    for (int i = 1; i <= totalsum; i++) 
        cache[0][i] = false; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalsum; j++) {
            cache[i][j] = cache[i-1][j];
            cache[i][j] |= (j >= arr[i-1]) ? cache[i-1][j-arr[i-1]] : false;
        }
    }
    int diff = INT_MAX;
    for (int i = totalsum/2; i >= 0; i--) {
        if (cache[n][i] == true) {
            diff = totalsum - (i * 2);
            break;
        }
    }

    return diff;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout << min_diff(arr, n);
}
