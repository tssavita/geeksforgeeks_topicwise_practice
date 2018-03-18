#include <iostream>
#include <algorithm>

using namespace std; 

/* The idea is to bring together elements that have a greater difference. This can be done by sorting an array and then calculating the difference between elements at the ends and coming closer towards the middle.  */

int max_sum_consecutive_difference(int arr[], int n) {
    sort(arr, arr+n);

    int sum = 0;

    for (int i = 0; i < n/2; i++) {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n-1 - i]);
    }

    return sum;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    cout << max_sum_consecutive_difference(arr, n);
}
