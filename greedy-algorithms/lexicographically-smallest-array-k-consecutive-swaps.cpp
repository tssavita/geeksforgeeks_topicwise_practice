#include <iostream>

using namespace std; 

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void after_swaps(int *arr, int n, int swaps) {
    for (int i = 0; ((i < n - 1) && (swaps > 0)); i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (j - i > swaps)
                return;
            if (arr[j] < arr[pos])
                pos = j;
        }
        for (int j = pos; j > i; j--)
            swap(arr[j], arr[j - 1]);

        swaps -= (pos - i);
    }
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

    for (int i = 0; i < n; i++)
        cout << arr[i];
}
