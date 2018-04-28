#include <iostream>

using namespace std; 

int maximum_sum(int *arr, int n) {
    int msis[n]; 
    int max = 0;
    for (int i = 0; i < n; i++) 
        msis[i] = arr[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (max < msis[i])
            max = msis[i];
    }

    return max; 
}

int main(int argc, char **argv) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout << maximum_sum(arr, n);
}
