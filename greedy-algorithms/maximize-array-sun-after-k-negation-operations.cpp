#include <iostream>
#include <climits>

using namespace std;

int maximize_array_sum(int *arr, int n, int k) {
    for (int i = 0; i < min(n, k); i++) {
        int min_val = INT_MAX;
        int min_index = -1; 
        for (int j = 0; j < n; j ++) {
            if (arr[j] < min_val) {
                min_val = arr[j];
                min_index = j; 
            }
        }
        if (min_val == 0)
            break;

        arr[min_index] = -arr[min_index];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += arr[i];

    return sum;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int k;
    cin>>k; 

    cout << maximize_array_sum(arr, n, k);
}
