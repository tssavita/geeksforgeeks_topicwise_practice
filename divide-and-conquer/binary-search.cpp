#include <iostream>

using namespace std;

int binary_search(int *arr, int low, int high, int find_ele) {
    if (high < low)
        return -1;
    int mid = (low + high) /2;
    if (find_ele == arr[mid]) 
        return mid;
    else if (find_ele <= arr[mid])
        return binary_search(arr, low, mid-1, find_ele);
    else 
        return binary_search(arr, mid+1, high, find_ele);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    int find_ele;
    cin>>find_ele;

    cout << binary_search(arr, 0, n-1, find_ele);
}
