#include <iostream>

using namespace std;

bool subset_sum(int arr[], int sum, int n) {
    if (sum == 0)
        return true;
    if (sum != 0 && n == 0)
        return false;
    if (arr[n-1] > sum)
        return subset_sum(arr, sum, n-1);
    else 
        return subset_sum(arr, sum, n-1) || subset_sum(arr, sum - arr[n-1], n-1);
}

bool partition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    return subset_sum(arr, sum/2, n);
}

int main(int argc, char ** argv) {
    int arr[5] = {3, 1, 5};
    cout << partition(arr, 5);
}
