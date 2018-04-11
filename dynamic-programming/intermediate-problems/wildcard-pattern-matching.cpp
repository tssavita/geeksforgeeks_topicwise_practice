#include <iostream>
#include <cstring>

using namespace std;

bool wildcard(string text, string pattern, int t, int p) {
    if (t == 0)
        return (p == 0);

    bool cache[t+1][p+1];
    memset(cache, false, sizeof(cache));
    cache[0][0] = true;
    for (int j = 1; j <= p; j++)
        cache[0][j] = cache[0][j-1];
    
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= p; j++) {
            if (pattern[j-1] == '*') 
                cache[i][j] = cache[i-1][j] || cache[i][j-1];
            else if (pattern[j-1] == '?' || pattern[j-1] == text[i-1])
                cache[i][j] = cache[i-1][j-1];
            else 
                cache[i][j] = false; 
        }
    }

    return cache[t][p];
}

bool wildcard(string text, string pattern) {
    return wildcard(text, pattern, text.size()-1, pattern.size()-1);
}

int main(int argc, char ** argv) {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    cout << wildcard(text, pattern);
}
