#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;

class minimum {
    public:
        int first;
        int second; 
        minimum(): first(0), second(0) {}
};

minimum min_numbers(vector<int> num) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < num.size(); i++)
        pq.push(num[i]);

    string s1, s2;
    minimum min1min2;

    while (pq.size() >= 2) {
        s1 += to_string(pq.top());
        pq.pop();

        s2 += to_string(pq.top());
        pq.pop();
    }
    if (pq.size() == 1) 
        s1 += pq.top();

    min1min2.first = stoi(s1.c_str());
    min1min2.second = stoi(s2.c_str());

    return min1min2;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> num;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        num.push_back(temp);
    }

    minimum min1min2 = min_numbers(num);

    cout << min1min2.first << " " << min1min2.second;
}
