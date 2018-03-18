#include <iostream>

using namespace std; 

int peak(int *arr, int n, int low, int high) {
    int mid = (low + high) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        mid == n - 1 || arr[mid + 1] <= arr[mid])
        return mid;

    else if (arr[mid - 1] > arr[mid])
        return peak(arr, n, low, mid - 1);
    else 
        return peak(arr, n, mid + 1, high);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i]; 

    cout << peak(arr, n, 0, n - 1);
}
