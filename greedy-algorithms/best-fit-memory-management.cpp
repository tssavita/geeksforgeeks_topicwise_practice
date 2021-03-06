#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int best_fit(vector<int> blocksize, vector<int> processrequest) {
    int allocation[processrequest.size()];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < processrequest.size(); i++) {
        int idx = -1;
        for (int j = 0; j < blocksize.size(); j++) {
            if (blocksize[j] >= processrequest[i]) {
                if (idx == -1)
                    idx = j;
                else if (blocksize[idx] > blocksize[j])
                    idx = j;
            }
        }
        if (idx != -1) {
            allocation[i] = idx;
            blocksize[idx] -= processrequest[i];
        }
    }

    for (int i = 0; i < processrequest.size(); i++) {
        cout << i + 1 << " " << processrequest[i] << " ";
        if (allocation[i] != -1)
            cout << allocation[i] + 1; 
        else 
            cout << "Not allocated";
        cout << endl;
    }
}

int main(int argc, char ** argv) {
    int m;
    int n; 
    cin>>m;
    cin>>n;
    vector<int> blocksize;
    vector<int> processrequest;
    for (int i = 0; i < m; i++) {
        int a;
        cin>>a;
        blocksize.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin>>b;
        processrequest.push_back(b);
    }
    best_fit(blocksize, processrequest);
}
