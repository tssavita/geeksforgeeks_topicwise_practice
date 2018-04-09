#include <iostream>
#include <cstring>

using namespace std;

long long int cache[10][500];

int count_ndigits_sum_util(int n, int sum) {
    if (n == 0)
        return sum == 0;
    if (cache[n][sum] != -1)
        return cache[n][sum];

    long long int count = 0;
    for (int i = 0; i <= 9; i++) {
        if (sum - i >= 0)
            count += count_ndigits_sum_util(n-1, sum-i);
    }
    cache[n][sum] = count;
    return count;
}

int count_ndigits_sum(int n, int sum) {
    memset(cache, -1, sizeof(cache));

    long long int ans = 0;
    for (int i = 1; i <= 9; i++) 
        if (sum - i >= 0)
            ans += count_ndigits_sum_util(n-1, sum-i);

    return ans;
}

int main(int argc, char ** argv) {
    int n, sum;
    cin>>n>>sum;

    cout << count_ndigits_sum(n, sum);
}
