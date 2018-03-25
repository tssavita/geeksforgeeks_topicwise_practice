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
#include <unordered_map>

using namespace std; 

class activity {
    public:
    int start;
    int end;
    activity(int s, int e): start(s), end(e) {}
};

bool compare(activity a1, activity a2) {
    return (a1.end < a2.end) ? true : false;
}

void activity_selection(vector<activity> times) {
    
    int last_job_end = times[0].end;
    vector<int> selected;
    selected.push_back(0);
    
    sort(times.begin(), times.end(), compare);
    
    for (int i = 1; i < times.size(); i++) {
        if (times[i].start >= last_job_end) {
            last_job_end = times[i].end;
            selected.push_back(i);
        }
    }
    
    for (int i = 0; i < selected.size(); i++)
        cout << selected[i] << " ";
    cout << endl;
}

int main() {
	int t; 
	cin>>t; 
	for (int i = 0; i < t; i++) {
	    int n;
	    cin>>n;
	    
	    vector<activity> times;
	    for (int j = 0; j < n; j++) {
	        int temp1, temp2;
	        cin>>temp1>>temp2;
	        activity temp(temp1, temp2);
	        times.push_back(temp);
	    }
	    activity_selection(times);
	}
	return 0;
}
