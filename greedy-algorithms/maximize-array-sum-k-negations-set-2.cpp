#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

int minimum(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

int maximize_sum(int *arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        sum += arr[i];
    }

    while (k-- > 0) {
        int min = pq.top();
        cout << min << endl;
        if (sum < (sum - min * 2)) {
            cout << sum << " " << sum - (min * 2) << endl;
            sum = (sum - min * 2);
            min *= -1;
            pq.pop();
            pq.push(min);
        }
    }

//    int sum = 0;
//    while ( !pq.empty() ) {
//        sum += pq.top();
//        pq.pop();
//    }

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

    cout << maximize_sum(arr, n, k);
}
