#include <iostream>

using namespace std;

int zz_length(int *arr, int n) {
    int cache[n+1][2];
    for (int i = 0; i <= n; i++) 
        cache[i][0] = cache[i][1] = 1;

    int result = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                cache[i][0] = max(cache[i][0], cache[i][1] + 1);
            else if (arr[i] < arr[j])
                cache[i][1] = max(cache[i][1], cache[i][0] + 1);
        }

        if (result < max(cache[i][0], cache[i][1]))
            result = max(cache[i][0], cache[i][1]);
    }
    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    cout << zz_length(arr, n);
}
