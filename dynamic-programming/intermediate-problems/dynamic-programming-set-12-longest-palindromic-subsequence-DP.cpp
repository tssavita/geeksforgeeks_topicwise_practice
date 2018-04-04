#include <iostream>

using namespace std; 

int partitions(string s) {
    int lps[s.size()][s.size()];

    for (int i = 0; i < s.size(); i++) 
        lps[i][i] = 1;

    int k;
    for (int i = 2; i <= s.size(); i++) {
        for (int j = 0; j <= s.size() - i + 1; j++) {
            k = i + j - 1;
            if (s[j] == s[k] && i == 2)
                lps[j][k] = 2;
            else if (s[j] == s[k])
                lps[j][k] = 2 + lps[j+1][k-1]; 
            else 
                lps[j][k] = max(lps[j+1][k], lps[j][k-1]);
        }
    }

    return lps[0][s.size()-1];
}

int main(int argc, char **argv) {
    string s;
    getline(cin, s);

    cout << partitions(s);
}
