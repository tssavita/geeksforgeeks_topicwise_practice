#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int first_fit(int blocksize[], int processrequest[], int m, int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (blocksize[j] >= processrequest[i]) {
                allocation[i] = j;
                blocksize[j] -= processrequest[i];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << processrequest[i] << " ";
        if (allocation[i] != -1)
            cout << allocation[i]+1;
        else 
            cout << "Not allocated";
        cout << endl;
    }
}

int main(int argc, char ** argv) {
    int arr1[5] = {100, 500, 200, 300, 600};
    int arr2[4] = {212, 417, 112, 426};
    first_fit(arr1, arr2, 5, 4);
}
