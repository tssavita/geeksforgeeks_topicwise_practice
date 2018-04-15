#include <iostream>

using namespace std;

int min(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

int min(int a, int b, int c) {
    return min(min(a,b), c);
}

int minimum_sum3(int *arr, int n) {
    int sum[n];
    sum[0] = arr[0];
    sum[1] = arr[1];
    sum[2] = arr[2];

    for (int i = 3; i < n; i++) 
        sum[i] = arr[i] + min(sum[i-3], sum[i-2], sum[i-1]);

    return min(sum[n-1], sum[n-2], sum[n-3]);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    cout << minimum_sum3(arr, n);
}
