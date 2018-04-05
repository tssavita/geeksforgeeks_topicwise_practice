#include <iostream>

using namespace std; 

bool is_equal(int arr[], int n, int sum) {
    if (sum == 0)
        return true; 

    if (n == 0 && sum != 0) 
        return false;

    if (arr[n-1] > sum)
        return is_equal(arr, n, sum);

    return is_equal(arr, n - 1, sum) || is_equal(arr, n - 1, sum - arr[n-1]);
}

bool partition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += arr[i]; 

    if (sum % 2 != 0)
        return false;

    return is_equal(arr, n, sum/2);
}

int main(int argc, char **argv) {   
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout <<partition(arr, n);
}
