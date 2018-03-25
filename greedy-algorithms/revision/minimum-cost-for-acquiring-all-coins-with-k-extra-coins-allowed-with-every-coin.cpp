#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int coins(int *arr, int n, int k) {
    sort(arr, arr + n);

    int ans = 0;
    for (int i = 0; i < ceil( n /(k + 1) ); i++)
        ans += arr[i];

    return ans;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    int k;
    cin>>k;

    cout << coins(arr, n, k);
}
