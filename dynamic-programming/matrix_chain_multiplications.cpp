#include <iostream>
#include <climits>

using namespace std;

int matrix_chain_mult_minop(int arr[], int start, int end) {
    if (start == end)
        return 0;

    int count = 0;
    int min = INT_MAX;

    for (int i = start; i < end; i++) {
        count = matrix_chain_mult_minop(arr, start, i) + 
            matrix_chain_mult_minop(arr, i+1, end) + 
            arr[start-1] * arr[i] * arr[end];
        if (count < min)
            min = count;
    }
    return min;
}

int main(int argc, char ** argv) {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << matrix_chain_mult_minop(arr, 1, n-1) << endl;
}
