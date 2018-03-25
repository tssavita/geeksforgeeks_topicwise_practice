#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int largest_sum(vector<int> arr) {
    int max_so_far = 0;
    int max_ending_here = 0;
    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i]; 
        if (max_ending_here < 0)
            max_ending_here = 0;

        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here; 
    }

    return max_so_far;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int j;
        cin>>j;
        arr.push_back(j);
    }
    cout << largest_sum(arr);
}
