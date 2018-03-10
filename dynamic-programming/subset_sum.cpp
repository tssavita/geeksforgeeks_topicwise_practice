#include <iostream>
#include <vector>

using namespace std;

bool subset_sum(vector<int> set, int n, int sum) {
    if (sum == 0) 
        return true;
    if (sum < 0)
        return false;
    if (set[n-1] > sum)
        return subset_sum(set, n-1, sum);
    
    return (subset_sum(set, n-1, sum) || subset_sum(set, n-1, sum-set[n-1]));
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    int sum;
    cin>>sum;
    cout << subset_sum(v, n, sum);
}
