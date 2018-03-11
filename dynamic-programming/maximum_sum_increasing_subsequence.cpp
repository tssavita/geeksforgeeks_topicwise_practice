#include <iostream>
#include <climits>

using namespace std;
 
int max_sum_subsequence(int arr[], int n) {
    int cache_maxsum[n];
    for (int i = 0; i < n; i++)
        cache_maxsum[i] = arr[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && cache_maxsum[i] < cache_maxsum[j] + arr[i])
                cache_maxsum[i] = cache_maxsum[j] + arr[i];
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (max < cache_maxsum[i])
            max = cache_maxsum[i];

    return max;
}

int main(int argc, char ** argv) {
    int arr[] = {1, 101, 2, 3, 100, 4, };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << max_sum_subsequence(arr, n);
}

