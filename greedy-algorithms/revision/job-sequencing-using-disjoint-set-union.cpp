#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class job {
    public:
        int id;
        int deadline; 
        int profit; 
        job(int i, int d, int p): id(i), deadline(d), profit(p) {}
};

class ds {
    public:
        int *parent;
        ds(int elements) {
            parent = new int[elements + 1];
            for (int i = 0; i < (elements + 1); i++)
                parent[i] = i;
        }
        
        int find(int child) {
            if (parent[child] == child)
                return child; 

            return find(parent[child]);
        }
        
        void unionds(int new_parent, int child) {
            parent[child] = new_parent;
        }
};

bool compare(job j1, job j2) {
    return (j1.profit > j2.profit) ? true : false;
}

int deadlines(vector<job> jobs) {
    int max = 0;
    for (int i = 0; i < jobs.size(); i++) {
        if (max < jobs[i].deadline)
            max = jobs[i].deadline;
    }
    return max;
}

void scheduling_jobs(vector<job> jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int max_deadline = deadlines(jobs);
    ds slots(max_deadline);

    for (int i = 0; i < jobs.size(); i++) {
        int available_slot = slots.find(jobs[i].deadline);
        if (available_slot > 0) {
            slots.unionds(slots.find(available_slot - 1), available_slot);
            cout << jobs[i].id << " ";
        }
    }
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n;

    vector<job> jobs;
    for (int i = 0; i < n; i++) {
        int id, deadline, profit;
        cin>>id>>deadline>>profit;
        job temp(id, deadline, profit);
        jobs.push_back(temp);
    }

    scheduling_jobs(jobs);
}
