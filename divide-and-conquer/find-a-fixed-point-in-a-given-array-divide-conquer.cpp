#include <iostream>
#include <vector>

using namespace std; 

int fixed_point(vector<int> arr, int low, int high) {
    if (arr.size() == 0) 
        return -1;

    int mid = (low + high) / 2;

    if (mid == arr[mid])
        return mid;
    else if (mid > arr[mid])
        return fixed_point(arr, mid + 1, high);
    else 
        return fixed_point(arr, 0, mid - 1);

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

    cout << fixed_point(arr,0, arr.size() - 1);
}
