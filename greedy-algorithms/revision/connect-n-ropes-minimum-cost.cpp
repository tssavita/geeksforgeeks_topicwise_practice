#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int connecting_ropes(vector<int> ropes) {

    if (ropes.size() == 1)
        return ropes[0];

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < ropes.size(); i++) 
        pq.push(ropes[i]);

    int sum = 0;
    int result = 0;
    while (pq.size() > 0) {
        int t1 = pq.top(); 
        pq.pop();

        sum = t1;

        if (pq.size() != 0) {

            int t2 = pq.top();
            pq.pop();

            sum += t2;
            result += sum;

            pq.push(sum);
        }
    }

    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> ropes;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        ropes.push_back(temp);
    }

    cout << connecting_ropes(ropes);
}
