#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

int max(int a, int b) {
    return a < b ? b : a;
}

int longest_common_subsequence(string x, string y) {
    if (x.length() == 0 || y.length() == 0) 
        return 0;
    else if (x[x.size()-1] == y[y.size()-1])
        return 1 + longest_common_subsequence(x.substr(0, x.length()-1), y.substr(0, y.length()-1));
    else 
        return max(longest_common_subsequence(x, y.substr(0, y.length()-1)),
            longest_common_subsequence(x.substr(0, x.length()-1), y));
}

int main(int argc, char ** argv) {
    string x = "AGGTAB";
    string y = "GXTXAYB";

    cout << longest_common_subsequence(x, y);
}
