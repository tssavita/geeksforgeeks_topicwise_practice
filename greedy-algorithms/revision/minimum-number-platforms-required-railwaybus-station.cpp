#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int platforms_required(vector<int> arr, vector<int> dep) {

    if (arr.size() != dep.size())
        return INT_MIN;

    if (arr.size() < 1 || dep.size() < 1)
        return INT_MIN;
    
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int pf = 0, max_pf = 0;

    for (int i = 0, j = 0; i < arr.size() && j < dep.size(); ) {
        if (arr[i] < dep[j]) {
            pf++; 
            i++;
            if (pf > max_pf)
                max_pf = pf;
        }
        else {
            pf--; 
            j++;
        }
    }
    
    return max_pf;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    vector<int> arrivals;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arrivals.push_back(temp);
    }

    vector<int> departures;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        departures.push_back(temp);
    }

    int pf = platforms_required(arrivals, departures);
    if (pf == INT_MIN)
        cout << "Invalid number of arrival and departure timings";

    cout << pf;
}
