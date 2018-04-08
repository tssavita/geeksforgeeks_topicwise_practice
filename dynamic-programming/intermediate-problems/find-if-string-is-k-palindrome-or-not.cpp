#include <iostream>
#include <algorithm>

using namespace std; 

int min(int a, int b) {
    return a < b ? a : b;
}

int k_palindrome(string s, string r) {
    int cache[s.size()+1][r.size()+1];

    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= r.size(); j++) {
            if (i == 0)
                cache[i][j] = j;
            else if (j == 0)
                cache[i][j] = i;
            else if (s[i-1] == r[j-1]) 
                cache[i][j] = cache[i-1][j-1];
            else 
                cache[i][j] = 1 + min(cache[i][j-1], cache[i-1][j]); 
        }
    }

    return cache[s.size()][r.size()];
}

bool k_palindrome(string s, int k) {
    string r = s;
    reverse(r.begin(), r.end());

    int len = k_palindrome(s, r);
    return (len <= (2 * k));
}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    int k;
    cin>>k;

    k_palindrome(s, k) ? cout << "Yes" : cout << "No";
}
