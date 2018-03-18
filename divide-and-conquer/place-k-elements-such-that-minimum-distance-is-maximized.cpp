#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

bool is_feasible(int *arr, int n, int elements, int current_min) {
    int current_elements = 1, current_diff = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] - current_diff > current_min) {
            current_diff = arr[i];
            current_elements++;
            if (current_elements == elements)
                return true;
        }
    }
    return false; 
}

int maximized_min_diff(int *arr, int n, int elements) {
    sort(arr, arr + n);

    int start = arr[0], end = arr[n - 1], max_min_diff = INT_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (is_feasible(arr, n, elements, mid)) {
            max_min_diff = max(max_min_diff, mid);
            start = mid + 1;
        }
        else 
            end = mid - 1;
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int elements;
    cin>>elements;

    cout << maximized_min_diff(arr, n, elements);
}
