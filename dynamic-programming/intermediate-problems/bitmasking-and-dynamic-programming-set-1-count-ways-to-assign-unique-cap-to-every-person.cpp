#include <iostream>
#include <vector>

using namespace std; 

vector<int> caps[1025][101];
int allmask;

long long ways(int mask, int i) {
    if (allmask == mask)
        return 1;
    if (i > 100)
        return 0;
    if (caps[mask][i] != -1)
        return caps[mask][i];

    long long int ways = ways_util(mask, i+1);
    int size = caps[i].size();

    for (int j = 0; j < size; j++) {
        if (mask & (1 << caps[i][j]))
            continue;
        else 
            ways += ways_util(mask | (1 << caps[i][j]), i+1);
        ways % 1000000007;
    }

    caps[mask][i] = ways;

    return ways; 
}

void count_ways(int n) {
    string temp, s;
    int x;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> temp) {
            stringstream s1; 
            s1 << temp;
            s1 >> x;
            caps[x].push_back(i);
        }
    }

    allmask = (1 << n) - 1; 
    memset(caps, -1, sizeof(caps));
    cout << count_util(0, 1); 
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    cout << count_ways(n);
}
