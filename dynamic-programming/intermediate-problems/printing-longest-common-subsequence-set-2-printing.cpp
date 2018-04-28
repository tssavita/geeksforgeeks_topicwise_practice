#include <iostream>
#include <set>

using namespace std; 

int **lcs;

set<string> all_lcs(string s1, string s2, int n, int m) {
    set<string> s;
    if (n == 0 || m == 0) {
        s.insert("");
        return s;
    }
    if (s1[m-1] == s2[n-1]) {
        set<string> t1 = all_lcs(s1, s2, n-1, m-1); 
        for (string i : t1)
            s.insert(i + s1[n-1]);
    }
    else {
        if (lcs[n-1][m] >= lcs[n][m-1]) 
            s = all_lcs(s1, s2, n-1, m);
        if (lcs[n][m-1] >= lcs[n-1][m]) {
            set<string> t1 = all_lcs(s1, s2, n, m-1);
            s.insert(t1.begin(), t1.end());
        }   
    }

    return s;
}

int len_lcs(string s1, string s2) {
    lcs = new int*[s1.length()+1];
    for (int i = 0; i <= s1.length(); i++)
        lcs[i] = new int[s2.length()+1];

    for (int i = 0; i <= s1.length(); i++) {
        for (int j = 0; j <= s2.length(); j++) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else 
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
    }

    return lcs[s1.length()][s2.length()];
}

int main(int argc, char ** argv) {
    string s1, s2; 
    getline(cin, s1);
    getline(cin, s2);

    cout << "Length of LCS " << len_lcs(s1, s2);
    set<string> s = all_lcs(s1, s2, s1.size(), s2.size());
    for (string temp : s)
        cout << temp << " "; 
}
