#include <iostream>

using namespace std;

int floor_search(int *arr, int low, int high, int x) {
    if (low > high)
        return -1;

    if (x >= arr[high])
        return high;

    int mid = (low + high) / 2;
    if (mid > 0 && arr[mid - 1] <= x && x < arr[mid])
        return mid; 

    else if (x < arr[mid])
        return floor_search(arr, low, mid - 1, x);
    else 
        return floor_search(arr, mid + 1, high, x);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int x;
    cin>>x;

    cout << floor_search(arr, 0, n - 1, x);
}
