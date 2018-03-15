#include <iostream>

using namespace std;

int merge(int arr[], int temp[], int low, int mid, int high) {
    int inversions = 0;

    int i = low, j = mid, k = high;
    
    while ((i < (mid-1)) && (j <= high)) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
            inversions += (mid - i);
        }
        k++;
    }

    while (i < mid-1) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
        arr[i] = temp[i];

    return inversions;
}

int _merge_sort(int arr[], int temp[], int low, int high) {
    int mid, inversion_count = 0;
    if (high > low) {
        mid = (low + high) / 2;
        inversion_count = _merge_sort(arr, temp, low, mid);
        inversion_count += _merge_sort(arr, temp, mid+1, high);
        inversion_count += merge(arr, temp, low, mid+1, high);
    }
    return inversion_count;
}

int merge_sort(int arr[], int n) {
    int *temp = new int[n];
    return _merge_sort(arr, temp, 0, n-1);
}

int main(int argc, char ** argv) {
    int arr[] = {1, 20, 6, 4, 5};
    merge_sort(arr, 5);
}
