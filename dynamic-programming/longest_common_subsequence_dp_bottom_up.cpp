#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std; 

int longest_common_subsequence(string x, string y) {

    int cache_lcs[x.length()+1][y.length()+1];
    for (int i = 0; i <= x.length(); i++) {
        for (int j = 0; j <= y.length(); j++) {
            if (i == 0 || j == 0) 
                cache_lcs[i][j] = 0;
            else if (x[i] == y[j])
                cache_lcs[i][j] = 1 + cache_lcs[i-1][j-1];
            else 
                cache_lcs[i][j] = max(cache_lcs[i][j-1], cache_lcs[i-1][j]);
        }
    }
    return cache_lcs[x.length()][y.length()];
}

int main(int argc, char ** argv) {
    string x = "AGGTAB";
    string y = "AGTXAYB";

    cout << longest_common_subsequence(x, y);
}
