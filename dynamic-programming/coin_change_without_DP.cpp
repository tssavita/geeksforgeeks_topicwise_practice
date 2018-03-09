#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std; 

int coinChanges(int sum, vector<int> changes, int current_coin) {
    int ways;
    if (sum < 0)
        return 0;
    else if (sum == 0)
        return 1;
    else {
        ways = 0;
        for (int i = current_coin; i < changes.size(); i++)
            ways += coinChanges(sum-changes[i], changes, i);
    }
        
    return ways;
}

int main() {
    int t;
    cin>>t;
    for (int j = 0; j < t; j++) {
        int n;
        cin>>n;

        vector<int> changes;
        for (int i = 0; i < n; i++) {
            int temp;
            cin>>temp;
            changes.push_back(temp);
        }

        int sum;
        cin>>sum;

        cout << coinChanges(sum, changes, 0) << endl;
    }
	
	return 0;
}
