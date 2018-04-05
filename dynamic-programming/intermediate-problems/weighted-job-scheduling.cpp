#include <iostream>
#include <algorithm>

using namespace std;

class job {
    public:
        int start;
        int end;
        int profit;
        job() {}
        job(int s, int e, int p): start(s), end(e), profit(p) {
        }
};

int max(int a, int b) {
    return a < b ? a : b;
}

bool compare_endtime(job j1, job j2) {
    return (j1.end < j2.end);
}

int non_conflicting(job arr[], int n) {
    for (int j = n - 1; j >= 0; j--) {
        if (arr[j].end < arr[n].start)
            return arr[j].profit;
    }
    return -1;
}

int weighted_scheduling_util(job arr[], int n) {

    if (n == 1)
        return arr[n-1].profit;

    int n_included = arr[n-1].profit;
    int prev = non_conflicting(arr, n);
    
    if (prev != -1)
        n_included += weighted_scheduling_util(arr, prev + 1);
    
    int n_excluded = weighted_scheduling_util(arr, n - 1);

    return max(n_included, n_excluded); 
}

int weight_scheduling(job arr[], int n) {
    sort(arr, arr + n, compare_endtime);

    return weighted_scheduling_util(arr, n);
}

int main(int argc, char **argv) {
    int n;
    cin>>n;

    job arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i].start;
        cin>>arr[i].end;
        cin>>arr[i].profit;
    }

    cout << weight_scheduling(arr, n);
}
