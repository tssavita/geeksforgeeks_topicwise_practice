#include <iostream>
#include <vector>
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

class weighted {
    public:
        vector<job> jobs;
        int value;
};

bool comparefunc(job j1, job j2) {
    return (j1.end < j2.end);
}

int binary_search(job *arr, int index) {
    int low = 0, high = index-1;
    while (low <= high) {
        int mid = (low + high)/2;
        if (arr[mid].end <= arr[index].end) {
            if (arr[mid+1].end <= arr[index].end)
                low = mid+1;
            else 
                return mid;
        }
        else 
            high = mid-1;
    }
    return -1;
}

void scheduled_jobs(job j[], int n) {
    sort(j, j + n, comparefunc);
    weighted cache[n];
    cache[0].value = j[0].profit;
    cache[0].jobs.push_back(j[0]);

    for (int i = 1; i < n; i++) {
        int incl_new = j[i].profit;
        int prev_nonconflict = binary_search(j, i);
        if (prev_nonconflict != -1)
            incl_new += cache[prev_nonconflict].value;
        if (incl_new > cache[i-1].value) {
            cache[i].value = incl_new;
            cache[i].jobs = cache[prev_nonconflict].jobs;
            cache[i].jobs.push_back(j[i]);
        }
        else 
            cache[i] = cache[i-1];
    }

    for (int i = 0; i < cache[n-1].jobs.size(); i++) {
        cout << cache[n-1].jobs[i].start << " " << cache[n-1].jobs[i].end << " " << cache[n-1].jobs[i].profit;
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    job j[n];
    for (int i = 0; i < n; i++) 
        cin>>j[i].start>>j[i].end>>j[i].profit;
    
    scheduled_jobs(j, n);
}
