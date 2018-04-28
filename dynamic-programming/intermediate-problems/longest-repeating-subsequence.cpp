#include <iostream>

using namespace std;

int longest_common_subsequence(string s) {
    int cache[s.size()+1][s.size()+1];
    for (int i = 0; i <= s.size(); i++)
        for (int j = 0; j <= s.size(); j++)
            cache[i][j] = 0;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            if (s[i-1] == s[j-1] && i != j)
                cache[i][j] = 1 + cache[i-1][j-1];
            else 
                cache[i][j] = max(cache[i][j-1], cache[i-1][j]);
        }
    }

    return cache[s.size()][s.size()];
}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    cout << longest_common_subsequence(s);
}
