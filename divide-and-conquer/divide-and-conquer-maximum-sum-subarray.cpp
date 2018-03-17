#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int max(int a, int b) {
    return a ^ ((a ^ b) & (-(a < b)));
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maximum_sum(vector<int> arr, int low, int mid, int high) {
    int sum_l = 0, maxsum_l = INT_MIN;
    for (int l = low; l <= mid; l++) {
        sum_l += arr[l];
        if (sum_l > maxsum_l)
            maxsum_l = sum_l;
    }

    int sum_r = 0, maxsum_r = INT_MIN;
    for (int r = mid+1; r <= high; r++) {
        sum_r += arr[r];
        if (sum_r > maxsum_r)
            maxsum_r = sum_r;
    }

    return maxsum_l + maxsum_r;
}

int maximum_sum_subarray(vector<int> arr, int low, int high) {
    if (low == high) 
        return arr[low];
    int mid = (low + high) / 2;

    return max(maximum_sum_subarray(arr, low, mid),
            maximum_sum_subarray(arr, mid + 1, high), 
            maximum_sum(arr, low, mid, high));
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

    cout << maximum_sum_subarray(arr, 0, arr.size() - 1);
}
