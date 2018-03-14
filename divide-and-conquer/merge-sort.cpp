#include <iostream>

using namespace std;

void merge(int *arr, int low, int mid, int high) {
    int n2 = high - mid;
    int n1 = mid - low + 1;

    int left[n1];
    for (int i = 0; i < n1; i++) 
        left[i] = arr[low + i];

    int right[n2];
    for (int j = 0; j < n2; j++) 
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    for (; i < n1; i++, k++) 
        arr[k] = left[i];

    for (; j < n2; j++, k++)
        arr[k] = right[j];
}

void merge_sort(int *arr, int low, int high) {
    if (high > low) {
        int mid = low + (high-low)/2;
        merge_sort(arr, low, mid-1);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    merge_sort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
