#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int min_max_diff_heights(vector<int> heights, int k) {

    sort(heights.begin(), heights.end());
    
    int ans = heights[heights.size() - 1] - heights[0];
    int big = heights[heights.size() - 1] - k;
    int small = heights[0] + k;

    if (small > big)
        swap(small, big);

    for (int i = 0; i < heights.size(); i++) {
        int sub = (heights[i] - k);
        int add = (heights[i] + k);

        if (sub >= small || add <= big)
            continue;

        if (big - sub <= add - small) 
            small = sub;
        else
            big = add;
    }

    return min(ans, big - small);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<int> heights;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        heights.push_back(temp);
    }

    cout << min_max_diff_heights(heights, k);
}
