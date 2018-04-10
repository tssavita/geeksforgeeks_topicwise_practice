#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std; 

int min(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

int find_min(int *arr, int n, int i, int totalsum, int subsum) {
    if (i == 0)
        return abs((totalsum-subsum) - subsum);
    return min(find_min(arr, n, i-1, totalsum, subsum + arr[i]), find_min(arr, n, i-1, totalsum, subsum));
}

int find_min(int *arr, int n) {
    int totalsum = 0;
    for (int i = 0; i < n; i++)
        totalsum += arr[i];

    return find_min(arr, n, n-1, totalsum, 0);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout << find_min(arr, n);
}
