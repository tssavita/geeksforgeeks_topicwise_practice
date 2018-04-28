#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int> > result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) 
            cout << result[i][j] << " ";
        cout << endl;
    }
}

void combination_sum_util(vector<int> &arr, int sum, vector<int> &r, vector<vector<int> > &result, int i) {
    if (sum < 0)
        return;
    if (sum == 0) {
        result.push_back(r);
        return;
    }
    while (i < arr.size() && sum - arr[i] >= 0) {
        r.push_back(arr[i]);
        combination_sum_util(arr, sum - arr[i], r, result, i);
        i += 1;
        r.pop_back();
    }
}

vector<vector<int> > combination_sum(vector<int> & arr, int sum) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> r;
    vector<vector<int> > result; 
    combination_sum_util(arr, sum, r, result, 0);
    return result;
}

int main(int argc, char **argv) {
    int n;
    cin>>n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int sum;
    cin>>sum;

    vector<vector<int> > res;
    res = combination_sum(arr, sum);
    print(res);
}
