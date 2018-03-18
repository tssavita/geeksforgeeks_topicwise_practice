#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class job {
    public:
    char id;
    int deadline;
    int profit;
};

int min(int a, int b) {
    return a < b;
}

bool by_desc_profit(job j1, job j2) {
    return j1.profit > j2.profit;
}

void job_scheduling(vector<job> jobs) {
    vector<bool> slot(jobs.size(), false); 
    int schedule[jobs.size()];

    sort(jobs.begin(), jobs.end(), by_desc_profit);

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = (min(jobs.size(), jobs[i].deadline) - 1); j >= 0; j--) {
            if (slot[j] == false) {
                slot[j] = true;
                schedule[j] = i;
                break;
            }
        }
    }

    for (int i = 0; i < jobs.size(); i++) {
        if (slot[i])
            cout << schedule[i] << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<job> jobs;
    for (int i = 0; i < n; i++) {
        char id;
        int deadline, profit; 
        cin>>id;
        cin>>deadline;
        cin>>profit;
        job temp;
        temp.id = id;
        temp.deadline = deadline;
        temp.profit = profit;
        jobs.push_back(temp);
    }

    job_scheduling(jobs);
}
