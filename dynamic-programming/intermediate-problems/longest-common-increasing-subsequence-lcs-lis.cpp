#include <iostream>

using namespace std;

int lcis(int *arr1, int n, int *arr2, int m) {
    int table[m];
    for (int i = 0; i < m; i++)
        table[i] = 0;
    for (int i = 0; i < n; i++) {
        int curr_len = 0;
        for (int j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                if ((curr_len + 1) > table[j]) {
                    table[j] = curr_len + 1; 
                    cout << "was here";
                }
            }
            if (arr1[i] > arr2[j]) {
                if (table[j] > curr_len)
                    curr_len = table[j];
            }
        }
    }

    int max_len = table[0];
    for (int i = 1; i < m; i++) {
        cout << table[i] << " ";
        if (max_len < table[i])
            max_len = table[i];
    }
    return max_len;
}

int main(int argc, char ** argv) {
    int n, m;
    cin>>n>>m;
    int *arr1 = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr1[i];
    int *arr2 = new int[m];
    for (int i = 0; i < m; i++)
        cin>>arr2[i];

    cout << lcis(arr1, n, arr2, m);
}
