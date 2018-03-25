#include <iostream>
#include <climits>

using namespace std;

int majority_element(int arr[], int n, int element) {
    int last_index = (n % 2 == 0) ? (n/2 + 1) : n/2;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element && arr[i + n / 2] == element)
            return element;
    }
    return INT_MIN;
}

int main(int argc, char ** argv) {
    int arr[] = {1, 2, 3, 4, 4, 4, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << majority_element(arr, n, 4);
}
