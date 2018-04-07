#include <iostream>
#include <climits>

using namespace std; 

int ans = INT_MAX;

int min(int a, int b) {
    return a < b ? a : b;
}

void make_partitions(int prev, int curr, int *arr, int n, int k, int sum) {
    if (prev > k)
        return;

    if (curr == k && prev == n-1) {
        ans = min(sum, INT_MAX); 
        return;
    }

    for (int j = prev + 1; j < n; j++) 
        make_partitions(j, curr + 1, arr, n, k, sum + ((arr[j]-arr[prev+1]) * (arr[j]-arr[prev+1])));
}    

int main(int argc, char **argv) { 
    int n;
    cin>>n; 
    
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int k;
    cin>>k;

    cout << ans;
}
