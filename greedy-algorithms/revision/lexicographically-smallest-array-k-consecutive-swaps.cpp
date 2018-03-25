#include <iostream>
#include <assert.h>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void after_swaps(int *arr, int n, int swaps) {
    assert (sizeof(arr) != 0);
    assert (swaps != 0);

    for (int i = 0; i < n - 1 && swaps > 0; i++) {
        int current = i;
        int remaining_max = arr[i];
    
        for (int j = i + 1; j < n; j++) {
            if ((j - i) > swaps)
                break;
            if (remaining_max > arr[j]) {
                remaining_max = arr[j];
                current = j;
            }
        }
        for (int j = current; j > i; j--)
            swap(arr[j], arr[j - 1]);

        swaps -= (current - i);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int swaps;
    cin>>swaps;

    after_swaps(arr, n, swaps);
}
