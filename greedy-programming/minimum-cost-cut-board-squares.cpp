#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_cost_board_cutting(vector<int> hzntl_edge_cost, vector<int> vrtcl_edge_cost) {
    int cost = 0; 
    int vrtcl = 1, hzntl = 1;

    int i = 0, j = 0;

    sort(hzntl_edge_cost.begin(), hzntl_edge_cost.end(), greater<int>());
    sort(vrtcl_edge_cost.begin(), vrtcl_edge_cost.end(), greater<int>());

    while ( i < hzntl_edge_cost.size() && j < vrtcl_edge_cost.size()) {
        if (hzntl_edge_cost[i] > vrtcl_edge_cost[j]) {
            cost += hzntl_edge_cost[i] * vrtcl;
            hzntl++;
            i++;
        }
        else {
            cost += vrtcl_edge_cost[j] * hzntl;
            vrtcl++;
            j++;
        }
    }

    int remaining = 0;
    while (i < hzntl_edge_cost.size()) {
        remaining += hzntl_edge_cost[i];
        i++;
    } 
    cost += (remaining * vrtcl);

    remaining = 0;
    while (j < vrtcl_edge_cost.size()) {
        remaining += vrtcl_edge_cost[j];
        j++;
    }
    cost += remaining * hzntl;

    return cost;
}

int main(int argc, char ** argv) {
    int m, n;
    cin>>m>>n;

    vector<int> hzntl_edge_cost;
    for (int i = 0; i < m; i++) {
        int temp;
        cin>>temp;
        hzntl_edge_cost.push_back(temp);
    }

    vector<int> vrtcl_edge_cost;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        vrtcl_edge_cost.push_back(temp);
    }
    
    cout << minimum_cost_board_cutting(hzntl_edge_cost, vrtcl_edge_cost);
}
