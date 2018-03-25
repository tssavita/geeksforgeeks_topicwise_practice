#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int sum_min_nums(vector<int> arr) {
    priority_queue<int, vector<int>, greater<int> >  pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }

    string num1, num2;

//    osstringstream oss;

    while ( !pq.empty() ) {
//        oss << pq.top();
//        num1 += oss.str();
        num1 += (48 + pq.top()); 
        pq.pop();

        if ( !pq.empty() ) {
            num2 += (48 + pq.top());
            pq.pop();
        }
    }

    int a = atoi(num1.c_str());
    int b = atoi(num2.c_str());

    return a + b;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout << sum_min_nums(arr);
}
