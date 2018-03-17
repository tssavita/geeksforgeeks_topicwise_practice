#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std; 

int min(int a, int b) { 
    return (a < b) ? a : b;
}

int get_sum(int *st, int sts, int ste, int qus, int que, int sti) {
    if (qus <= sts || que >= ste)
        return st[sti];

    if (sts < qus || ste > que)
        return INT_MAX;

    int mid = sts + (ste - sts) / 2;

    return min(get_sum(st, sts, mid, qus, que, 2 * sti + 1),  
        get_sum(st, mid + 1, ste, qus, que, (2 * sti) + 2));
}

int get_sum(int *st, int st_size, int qus, int que) {

    if (qus < 0 || que > (st_size - 1) || que < qus)
        return -1; 

    return get_sum(st, 0, st_size - 1, qus, que, 0);
}

int update_stree(int *st, int sts, int ste, int index, int diff, int sti) {
    if (index < sts || index > ste) { 
        return -1; 
    }

    st[sti] += diff;
    if (sts != ste) {
        int mid = sts + (ste - sts) / 2;
        update_stree(st, sts, mid, index, diff, sti * 2 + 1);
        update_stree(st, mid + 1, ste, index, diff, sti * 2 + 2);
    }

}

int update_stree(vector<int> arr, int *st, int st_size, int index, int new_value) {
    if (index < 0 || index > st_size) 
        return -1;

    int diff = new_value - arr[index];

    arr[index] = diff; 

    update_stree(st, 0, st_size - 1, index, new_value, 0); 
}

int construct_stree(vector<int> arr, int arrs, int arre, int *stree, int sti) {
    if (arrs == arre) {
        stree[sti] = arr[arrs];
        return arr[arrs];
    }

    int mid = arrs + (arre - arrs) / 2;

    stree[sti] = min(construct_stree(arr, arrs, mid, stree, 2 * sti + 1),
        construct_stree(arr, mid + 1, arre, stree, 2 * sti + 2));

    return stree[sti];
}

int *construct_stree(vector<int> arr) {
    int x = log2(arr.size());
    int stree_size = 2 * arr.size() - 1;
    // OR 
    // int stree_size = 2 * arr.size() - 1;
    int *stree = new int[stree_size];

    construct_stree(arr, 0, arr.size() - 1, stree, 0); 
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

    int *st = construct_stree(arr);

    cout << get_sum(st, arr.size(), 1, 3) << endl;

    update_stree(arr, st, arr.size(), 1, 10); 

    cout << get_sum(st, arr.size(), 1, 3) << endl;
}
