#include <iostream>
#include <vector>

using namespace std;

int coin_change(vector<int>change, int sum) {
    int cache[sum+1][change.size()];

    for (int i = 0; i <= sum; i++)
        cache[0][i] = 1;
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < change.size(); j++) {
            // Including at least 1 time, the j-th currency
            int x = (i - change[j] >= 0) ? cache[i - change[j]][j]: 0;
            // Excluding the j-th currency
            int y = (j >= 1) ? cache[i][j-1] : 0;
            cache[i][j] = x + y;
        }
    }

    return cache[sum][change.size()-1];
}

int main(int argc, char ** argv) {
    int t;
    cin>>t; 

    for (int i = 0; i < t; i++) {
        int n;
        cin>>n;

        vector<int> change;
        for (int j = 0; j < n; j++) {
            int temp;
            cin>>temp;
            change.push_back(temp);
        }

        int sum;
        cin>>sum;
        
        cout << coin_change(change, sum); 
    }
}
