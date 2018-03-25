#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int q = arr[high];
    int j = low-1;
    for (int i = low; i <= high-1; i++) {
        if (arr[i] <= q) {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j+1], &arr[high]);
    return (j+1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        quick_sort(arr, low, part-1);
        quick_sort(arr, part+1, high);
    }
}

void print_sorted_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    quick_sort(arr, 0, n-1);

    print_sorted_arr(arr, n);
}
