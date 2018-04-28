#include <iostream>

using namespace std; 

int min(int a, int b) {
    return a < b ? a : b;
}

int mintime_skipalt(int *arr, int n) {
    int i = arr[0];
    int e = 0;

    for (int j = 1; j < n; j++) {
        int i_new = arr[j] + min(i, e);
        int e_new = i;

        i = i_new;
        e = e_new;
    }

    return min(i, e);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout << mintime_skipalt(arr, n);
}
