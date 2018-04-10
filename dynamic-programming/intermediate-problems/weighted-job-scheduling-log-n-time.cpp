#include <iostream>
#include <algorithm>

using namespace std; 

class job {
    public:
        int start;
        int end;
        int profit;
        job() {}
        job(int s, int e, int p): start(s), end(e), profit(p) {}
};

int binary_search(job arr[], int index) {
    int low = 0, high = index - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].end <= arr[index].start) {
            if (arr[mid+1].end <= arr[index].start)
                low = mid+1;
            else 
                return mid;
        }
        else 
            high = mid - 1;
    }
    return -1; 
}

bool compareprofit(job &a, job &b) {
    return (a.end < b.end);
}

int max_profit(job arr[], int n) {

    sort(arr, arr+n, compareprofit);
    int *table = new int[n];
    table[0] = arr[0].profit;
    for (int i = 1; i < n; i++) {
        int i_included = arr[i].profit;
        int prev_nonconflict = binary_search(arr, i);
        if (prev_nonconflict != -1)
            i_included += table[prev_nonconflict];

        table[i] = max(i_included, table[i-1]);
    }

    return table[n-1];
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    cout << max_profit(arr, n);
}
