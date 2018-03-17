#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class pair_min_max {
    public:
    int min;
    int max;
    pair_min_max(): min(INT_MAX), max(INT_MIN) {};
};

pair_min_max get_min_max(vector<int> arr) {
    pair_min_max min_max;

    if (arr.size() == 1) {
        min_max.min = arr[0];
        min_max.min = arr[0];
    }
    else if (arr.size() == 2) {
        if (arr[0] < arr[1]) {
            min_max.min = arr[0];
            min_max.max = arr[1];
        }
        else {
            min_max.min = arr[1];
            min_max.max = arr[0];
        }
    }
    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] < arr[i + 1]) {
            if (min_max.min > arr[i]) 
                min_max.min = arr[i];
            else if (min_max.max < arr[i + 1])
                min_max.max = arr[i + 1];
        }
        else {
            if (min_max.min > arr[i + 1])
                min_max.min = arr[i + 1];
            else if (min_max.max < arr[i])
                min_max.max = arr[i];
        }
    }

    return min_max;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr;
    for (int i = 0; i < n; i ++) {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    pair_min_max p1 = get_min_max(arr);

    cout << p1.min << " " << p1.max;
}
