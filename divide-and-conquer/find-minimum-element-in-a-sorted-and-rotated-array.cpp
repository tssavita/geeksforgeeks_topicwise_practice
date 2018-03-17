#include <iostream>
#include <vector>

using namespace std;

int min_element_rotated_array(vector<int> arr, int low, int high) {
    if (high < low)
        return arr[0];

    if (low == high)
        return arr[low];

    int mid = (low + high) / 2; 

    if (mid < high && arr[mid] > arr[mid+1])
        return arr[mid+1];
    else if (mid > low && arr[mid] < arr[mid-1])
        return arr[mid];

    if (arr[high] > arr[mid])
        return min_element_rotated_array(arr, low, mid-1);

    return min_element_rotated_array(arr, mid+1, high);
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

    cout << min_element_rotated_array(arr, 0, arr.size()-1);
}
