#include <iostream>
#include <vector>

using namespace std;

int bitonic_element(vector<int> arr, int low, int high) {
    if (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return arr[mid];

        if (arr[mid] < arr[mid + 1])
            return bitonic_element(arr, mid + 1, high);
        else 
            return bitonic_element(arr, low, mid - 1);
    }
    return -1;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout << bitonic_element(arr, 0, arr.size()-2);
}
