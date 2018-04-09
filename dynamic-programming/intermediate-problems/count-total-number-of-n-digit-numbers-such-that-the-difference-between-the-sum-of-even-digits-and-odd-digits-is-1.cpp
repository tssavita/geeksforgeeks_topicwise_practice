#include <iostream>
#include <cstring>

using namespace std; 

int cache[50][1000][1000][2];

int count_util(int digit, int esum, int osum, bool is_even, int n) {
    if (digit == n)
        return (esum - osum == 1);

    if (cache[digit][esum][osum][is_even] != -1) 
        return cache[digit][esum][osum][is_even];

    long long int result = 0;
    if (is_even)
        for (int i = 0; i <= 9; i++) 
            result += count_util(digit+1, esum+i, osum, false, n);
    else 
        for (int i = 0; i <= 9; i++)
            result += count_util(digit+1, esum, osum+i, true, n);

    cache[digit][esum][osum][is_even] = result;
    return result; 
}

int count(int n) {
    memset(cache, -1, sizeof(cache));
    long long int result = 0, esum = 0, osum = 0;
    for (int i = 1; i <= 9; i++)
        result += count_util(1, esum+i, osum, true, n);

    return result; 
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    cout << count(n);
}
