#include <iostream>
#include <vector>
#include <assert.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

int sum_max_diff_consecutive(vector<int> arr) {
    assert(arr.size() > 0);

    if (arr.size() == 1)
        return 0;

    sort(arr.begin(), arr.end());

    vector<int> temp;
    int start = 0, end = arr.size() - 1, sum = 0;
    while (start < end) {
        temp.push_back(arr[start]);
        temp.push_back(arr[end]);
        start++;
        end--;
    }
    if (start == end)
        temp.push_back(arr[start]);

    for (int i = 0; i < arr.size(); i++)
        cout << temp[i] << " ";

    for (int i = 1; i < arr.size(); i++) 
        sum += abs(temp[i] - temp[i - 1]);

    return (sum + abs(temp[temp.size() - 1] - temp[0]));
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

    cout << sum_max_diff_consecutive(arr);
}
