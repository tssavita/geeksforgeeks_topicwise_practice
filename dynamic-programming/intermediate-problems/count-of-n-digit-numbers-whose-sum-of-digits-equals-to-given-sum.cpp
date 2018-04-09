#include <iostream>

using namespace std;

int count_util(int n, int sum) {
    if (n == 0)
        return (sum == 0); 

    if (sum == 0)
        return 1; 

    long long int count = 0;
    for (int i = 0; i <= 9; i++) {
        if (sum - i >= 0)
            count += count_util(n-1, sum-i);
    }

    return count;
}

int count(int n, int sum) {
    long long int count = 0; 
    for (int i = 1; i <= 9; i++) {
        if (sum-i >= 0)
            count += count_util(n-1, sum-i);
    }

    return count;
}

int main(int argc, char ** argv) {
    int n, sum;
    cin>>n>>sum;

    cout << count(n, sum);
}
