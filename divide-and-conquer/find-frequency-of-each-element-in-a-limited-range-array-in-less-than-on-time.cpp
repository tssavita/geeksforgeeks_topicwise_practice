#include <iostream>
#include <vector>

using namespace std; 

void find_frequency(int *arr, int low, int high, vector<int>& frequency) {
    if (arr[low] == arr[high]) {
        frequency[arr[low]] += (high - low + 1);
        cout << frequency[low] << endl << endl;
    }
    else {
        int mid = (low + high) / 2;
        find_frequency(arr, low, mid, frequency);
        find_frequency(arr, mid + 1, high, frequency);
    }
}

void find_frequency(int *arr, int n) {
    if (n <= 0)
        return;

    vector<int> frequency(arr[n-1] + 1, 0);

    find_frequency(arr, 0, n - 1, frequency);

    for (int i = 0; i <= arr[n - 1]; i++) 
        cout << i << " " << frequency[i] << endl;
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    find_frequency(arr, n);
}
