#include <iostream>

using namespace std; 

int min(int a, int b) {
    return a < b ? a : b;
}

int min_of_array(int *arr, int l, int h) {
    int min_ele = arr[l];
    for (int i = l + 1; i <= h; i++)
        if (min_ele > arr[i])
            min_ele = arr[i];

    return min_ele;
}

int max_of_array(int *arr, int l, int h) {
    int max_ele = arr[l];
    for (int i = l + 1; i <= h; i++) 
        if (max_ele < arr[i])
            max_ele = arr[i];

    return max_ele;
}

int min_removals(int *arr, int n, int i, int j) {
    if (i >= j) 
        return 0;

    int s = min_of_array(arr, i, j); 
    int b = max_of_array(arr, i, j);

    if ((s * 2) > b)
        return 0;

    return min( min_removals(arr, n, i+1, j), min_removals(arr, n, i, j-1)) + 1;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i =  0; i < n; i++)
        cin>>arr[i];

    cout << min_removals(arr, n, 0, n-1);
}
