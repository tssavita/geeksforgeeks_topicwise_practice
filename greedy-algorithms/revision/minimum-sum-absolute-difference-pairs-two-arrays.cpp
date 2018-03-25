#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

#define NDEBUG

using namespace std;

int min_abs_diff(vector<int> a, vector<int> b) {
    assert(a.size() == b.size());
    assert(a.size() != 0 || b.size() != 0);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        diff += abs(a[i] - b[i]);
    }

    return diff;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    vector<int> b;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        b.push_back(temp);
    }

    int diff = min_abs_diff(a, b);
    if (diff < 0)
        cout << "Invalid input";
    else 
        cout << diff;
}
