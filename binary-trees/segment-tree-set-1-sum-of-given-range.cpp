#include <iostream>
#include <vector>

using namespace std;

int get_mid(int ststart, int stend) {
    return ststart + (stend - ststart) / 2;
}

int get_sum_util(int *stree, int ststart, int stend, int querystart, int queryend, int curr) {
    if (ststart <= querystart || stend >= queryend) 
        return stree[curr];

    if (stend < querystart || ststart > queryend)
        return 0;

    int mid = get_mid(ststart, stend);

    return get_sum_util(stree, ststart, mid, querystart, queryend, 2 * curr + 1) +
            get_sum_util(stree, mid + 1, stend, querystart, queryend, 2 * curr + 2);
}

int get_sum(int *stree, int st_size, int querystart, int queryend) {
    if (querystart < 0 || queryend > st_size - 1 || queryend < querystart) {
        return -1; 
    }

    return get_sum_util(stree, 0, st_size - 1, querystart, queryend, 0);
}

void update_value_util(int *st, int ststart, int stend, int curr, int new_val) {
    if (curr < ststart || curr > stend) 
        return;

    st[curr] = st[curr] + new_val;
    
    if (stend != ststart) {
        int mid = get_mid(ststart, stend);
        update_value_util(st, ststart, mid, 2 * curr + 1, new_val);
        update_value_util(st, mid + 1, stend, 2 * curr + 2, new_val);
    }

}

void update_value(vector<int> arr, int *st, int st_size, int curr, int new_val) {
    if (curr < 0 || curr > (st_size - 1))
        return;

    int diff = new_val - arr[curr];

    arr[curr] = new_val;

    update_value_util(st, 0, arr.size(), 0, diff);
}

int construct_segment_tree(vector<int> arr, int *stree, int segstart, int segend, int curr) {

    if (segstart == segend) {
        stree[curr] = arr[segstart];
        return arr[segstart];
    }

    int mid = get_mid(segstart, segend);
    stree[curr] = construct_segment_tree(arr, stree, segstart, mid, 2 * curr + 1) + 
                    construct_segment_tree(arr, stree, mid + 1, segend, 2 * curr + 2);

    return stree[curr];
}

int *construct_segment_tree(vector<int> arr, int segstart, int segend) {

    int *stree = new int[2 * arr.size()-1];

//    if (segstart == segend) 
    construct_segment_tree(arr, stree, 0, arr.size() - 1, 0);
        
    return stree;
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

    int *st = construct_segment_tree(arr, 0, arr.size() - 1);

    cout << get_sum(st, arr.size(), 1, 3) << endl;
    
    update_value(arr, st, arr.size(), 1, 10);

    cout << get_sum(st, arr.size(), 1, 3) << endl;
}
