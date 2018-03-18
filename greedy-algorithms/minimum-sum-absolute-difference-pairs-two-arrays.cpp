#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_absolute_sum(vector<int> arr1, vector<int> arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int absolute_diff = 0;

    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " " << arr2[i] << " " << abs(arr1[i] - arr2[i]) << endl;
        absolute_diff += abs(arr1[i] - arr2[i]);
    }

    return absolute_diff;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr1, arr2;

    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin>>temp1>>temp2;
        arr1.push_back(temp1);
        arr2.push_back(temp2);
    }
    cout << minimum_absolute_sum(arr1, arr2);
}
