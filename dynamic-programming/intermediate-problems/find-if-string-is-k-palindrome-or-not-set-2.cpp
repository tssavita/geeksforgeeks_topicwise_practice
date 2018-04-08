#include <iostream>
#include <algorithm>

using namespace std; 

bool k_palindrome(string s, string r) {
    int cache[s.size() + 1][r.size() + 1];
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= r.size(); j++) {
            if (i == 0 || j == 0)
                cache[i][j] = 0;
            else if (s[i-1] == r[j-1])
                cache[i][j] = cache[i-1][j-1] + 1;
            else 
                cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
        }
    } 

    return cache[s.size()][r.size()];
}

bool k_palindrome(string s, int k) {
    string rev = s; 
    reverse(rev.begin(), rev.end());

    int lcs = k_palindrome(s, rev);

    return ((s.size() - lcs) <= k);
}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    int k;
    cin>>k;

    k_palindrome(s, k) ? cout << "Yes" : cout << "No"; 
}
