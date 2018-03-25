#include <iostream>
#include <algorithm>

using namespace std;

int after_k_modifications(int *arr, int n, int k) {

    if (k == 0 || n == 0)
        return 0;

    int i = 0;
    int sum = 0;
    
    sort(arr, arr + n);

    for (int j = 0; j < n; j++)
        sum += arr[j];

    while (i < n && k > 0) {
        if (arr[i] < 0) {
            sum += (-2 * arr[i]);
            k--;
        }
        else 
            break;
        i++;
    }

    return sum;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int k;
    cin>>k;

    cout << after_k_modifications(arr, n, k);
}
