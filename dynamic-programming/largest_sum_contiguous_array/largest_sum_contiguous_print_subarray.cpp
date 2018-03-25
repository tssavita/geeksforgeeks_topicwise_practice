#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void largest_sum_array(int arr[], int arr_size) {
    int start = 0, end = 0;
    int max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < arr_size; i++) {
        max_ending_here += arr[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
            start = i + 1;
            end = i + 1;
        }
        else if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here; 
            end = i;
        }
    }

    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    largest_sum_array(arr, n);
}
