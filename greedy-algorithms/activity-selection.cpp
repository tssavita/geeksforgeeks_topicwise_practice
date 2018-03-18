#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std; 

bool sort_by_second(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void activities_selected(vector<pair<int, int> > activity_times) {
    vector<pair<int, int> >::iterator it1 = activity_times.begin();

    sort(activity_times.begin(), activity_times.end(), sort_by_second);
    
    cout << it1->first << " " << it1->second << endl;

    for (vector<pair<int, int> >::iterator it2 = activity_times.begin()+1; it2 != activity_times.end(); it2++) {
        if (it2->first >= it1->second) {
            cout << it2->first << " " << it2->second << endl;
            it1 = it2;
        }
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<pair<int, int> > activity_times;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin>>first;
        cin>>second;
        activity_times.push_back(make_pair(first, second));
    }

    activities_selected(activity_times);
}
