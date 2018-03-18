#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std; 

int get_max(vector<int> jobs) {
    int result = INT_MAX;
    for (int i = 0; i < jobs.size(); i++) 
        if (result < jobs[i])
            result = jobs[i];

    return result; 
}

int isPossible(int time, int assignees, vector<int> jobs) {
    int count = 1;
    int current_time = 0;

    for (int i = 0; i < jobs.size(); ) {
        if (current_time + jobs[i] > time) {
            current_time = 0;
            count++;
        }
        else {
            current_time += jobs[i];
            i++;
        }
    }
    return (count <= assignees);
}

int find_min_time(int assignees, int work_time_unit, vector<int> jobs) {

    int start = 0, end = 0;
    
    for (int i = 0; i < jobs.size(); i++)
        end += jobs[i];

    int ans = end;

    int job_max = get_max(jobs);

    while (start <= end) {
        int mid = (start + end)/2; 
        if (job_max >= mid && isPossible(mid, assignees, jobs)) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else 
            end = mid + 1;
    }

    return ans * work_time_unit;
}

int main(int argc, char ** argv) {
    vector<int> jobs;
    int assignees = 4;
    int work_time_unit = 5;
    for (int i = 0; i < 6; i++) {
        int temp;
        cin>>temp;
        jobs.push_back(temp);
    }
    cout << find_min_time(assignees, work_time_unit, jobs);
}
