#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int after_k_modifications(vector<int> arr, int n, int k) {
    if (n == 0 || k == 0)
        return 0;

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) 
        pq.push(arr[i]);

    while ( k > 0 ) {
        int temp = pq.top();
        pq.pop();
        temp *= -1;
        pq.push(temp);
        k--;
    }

    int sum = 0;
    while ( !pq.empty() ) {
        sum += pq.top();
        pq.pop();
    }
    
    return sum;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int k;
    cin>>k;

    cout << after_k_modifications(arr, n, k);
}
