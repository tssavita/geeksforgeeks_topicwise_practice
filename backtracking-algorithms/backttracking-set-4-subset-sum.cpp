#include <iostream>

using namespace std; 

static int total_nodes;

void print(int *tuple, int t) {
    for (int i = 0; i < t; i++)
        cout << tuple[i] << " ";
} 

void subset_sum(int *arr, int *tuple, int n, int t, int s, int si, int i) {
    total_nodes++;
    if (si == s) {
        print(tuple, t);
//        if (i + 1 < n && si + arr[i] <= s)
            subset_sum(arr, tuple, n, t - 1, s, si - arr[i], i + 1);
        return;
    }
    else {
//        if (i < n && si + arr[i] <= s) {
            for (int j = i; j < n; j++) {
                tuple[t] = arr[j];
                subset_sum(arr, tuple, n, t + 1, s, si + arr[j], j + 1);
            }
//        }
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int *tuple = new int[n];
    subset_sum(arr, tuple, n, 0, k, 0, 0);

    cout << total_nodes;
}
