#include <iostream>
#include <vector>

#include "pair_min_max.h"

using namespace std;

pair_min_max get_min_max(vector<int> arr, int low, int high) {
    pair_min_max p; 
    if (arr.size() == 1) {
        p.min = arr[0];
        p.max = arr[0];
    }
    
    if (arr.size() == 2) {
        if (arr[0] < arr[1]) {
            p.min = arr[0];
            p.max = arr[1];
        }
        else {
            p.min = arr[1];
            p.max = arr[0];
        }
    }

    int mid = (low + high) / 2;
    pair_min_max l = get_min_max(arr, low, mid);
    pair_min_max r = get_min_max(arr, mid + 1, high);

    if (l.min < r.min)
        p.min = l.min;
    else 
        p.min = r.min;

    if (l.max < r.max)
        p.max = l.max;
    else 
        p.max = r.max;

    return p;
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

    pair_min_max pmn = get_min_max(arr, 0, arr.size() - 1);
    cout << pmn.min << " " << pmn.max;
}
