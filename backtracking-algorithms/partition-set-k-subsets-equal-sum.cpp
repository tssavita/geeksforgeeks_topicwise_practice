#include <iostream>

using namespace std;

bool is_k_partition_possible_util(int *arr, int n, int *subsum, bool *included, int subset, int k, int curr, int limit) {
    if (subsum[curr] == subset) {
        if (curr == k - 2) 
            return true;
        is_k_partition_possible_util(arr, n, subsum, included, subset, k, curr + 1, n - 1); 
    }
    for (int i = limit; i>= 0; i--) {
        if (included[i])
            continue;
        int temp = subsum[curr] + arr[i];

        if (temp <= subset) {
            included[i] = true;
            subsum[curr] += arr[i];

            bool next = is_k_partition_possible_util(arr, n, subsum, included, subset, k, curr, i - 1);
            included[i] = false;
            subsum[curr] -= arr[i];
            if (next)
                return true;
        }
    }
}

bool is_k_partition_possible(int *arr, int n, int k) {
    if (k == 1)
        return true;
    if (k > n)
        return false; 

    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += arr[i];

    if (sum % k != 0)
        return false; 

    int subset = sum / k;

    int *subsum = new int[n];
    bool *included = new bool[n];
    for (int i = 0; i < n; i++) {
        subsum[i] = 0;
        included[i] = false; 
    }

    subsum[0] = arr[n - 1];
    included[n - 1] = true;

    return is_k_partition_possible_util(arr, n, subsum, included, subset, k, 0, n - 1);
}

int main(int argc, char **argv) {
    int n;
    cin>>n; 

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    int k;
    cin>>k;
    
    if(is_k_partition_possible(arr, n, k))
        cout << "Possible";
    else 
        cout << "Not possible";
}
