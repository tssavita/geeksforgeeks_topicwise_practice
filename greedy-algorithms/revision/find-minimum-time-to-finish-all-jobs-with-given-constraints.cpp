#include <iostream>

using namespace std; 

int get_biggest_job(int *jobs, int n) {
    int max = jobs[0];
    for (int i = 1; i < n; i++) {
        if (jobs[i] > max) {
            max = jobs[i];
        }
    }
    return max;
}

bool is_possible(int k, int t, int *jobs, int n) {
    int assignees = 1; 
    int curr_assignee_time = 0;

    for (int i = 0; i < n; ) {
        if (curr_assignee_time + jobs[i] > t) {
            assignees++;
            curr_assignee_time = 0;
        }
        else {
            curr_assignee_time += jobs[i];
            i++;
        }
    }

    return (assignees <= k);
}

int min_time(int k, int t, int *jobs, int n) {
    int start = 0, end = 0;

    for (int i = 0; i < n; i++) 
        end += jobs[i];

    int ans = end;

    int biggest_job = get_biggest_job(jobs, n);

    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid >= biggest_job && is_possible(k, mid, jobs, n)) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else 
            start = mid + 1;
    }

    return t * ans;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int k;
    cin>>k;

    int t;
    cin>>t;

    int *jobs = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>jobs[i];

    cout << min_time(k, t, jobs, n);
}
