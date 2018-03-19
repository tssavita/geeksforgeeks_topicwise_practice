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

int min(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

bool compare(job j1, job j2) {
    return (j1.profit > j2.profit)? true : false;
}

void scheduling_order(vector<job> jobs) {

    sort(jobs.begin(), jobs.end(), compare);
    for (int i = 0; i < jobs.size(); i++)

    vector<int> order(jobs.size()); 
    vector<bool> slots(jobs.size(), false);

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = min(jobs.size(), jobs[i].deadline) - 1; j >= 0; j--) {
            if (slots[j] == false) {
                slots[j] = true;
                order[j] = jobs[i].id;
                break;
            }
        }  
    }

    for (int i = 0; i < order.size(); i++) 
        if (slots[i] == true)
            cout << order[i] << " ";

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

    scheduling_order(jobs);
}
