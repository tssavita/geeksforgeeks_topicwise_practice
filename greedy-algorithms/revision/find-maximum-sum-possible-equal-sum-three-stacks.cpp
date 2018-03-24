#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

int max_sum_possible(stack<int> s1, stack<int> s2, stack<int> s3, int sum1, int sum2, int sum3) {


    while (true) {
        if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0)
            return 0;

        if (sum1 == sum2 && sum2 == sum3)
            return sum1; 

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= s1.top();
            s1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= s2.top();
            s2.pop();
        }
        else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= s3.top();
            s3.pop();
        }
    }
}

int main(int argc, char ** argv) {
    int n1;
    cin>>n1;

    stack<int> s1;
    int sum1 = 0;
    for (int i = 0; i < n1; i++) {
        int temp;
        cin>>temp;
        sum1 += temp;
        s1.push(temp);
    }

    int n2; 
    cin>>n2;

    stack<int> s2;
    int sum2 = 0;
    for (int i = 0; i < n2; i++) {
        int temp;
        cin>>temp;
        sum2 += temp;
        s2.push(temp);
    }

    int n3;
    cin>>n3;

    stack<int> s3;
    int sum3 = 0;
    for (int i = 0; i < n3; i++) {
        int temp;
        cin>>temp;
        sum3 += temp;
        s3.push(temp);
    }

    cout << max_sum_possible(s1, s2, s3, sum1, sum2, sum3);
}
