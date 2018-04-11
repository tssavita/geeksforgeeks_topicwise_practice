#include <iostream>

using namespace std;

int **lcs;

int max(int a, int b) {
    return a > b ? a : b;
}

int cost(string s1, string s2) {
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

int string_identical_cost(string s1, string s2, int s1cost, int s2cost) {
    lcs = new int*[s1.length()+1];
    for (int i = 0; i <= s1.length(); i++) {
        lcs[i] = new int[s2.length()+1];
    }

    int cs = cost(s1, s2);

    return s1cost * (s1.length() - cs) + s2cost * (s2.length() - cs);
}

int main(int argc, char ** argv) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int s1cost, s2cost;
    cin>>s1cost>>s2cost;

    cout << string_identical_cost(s1, s2, s1cost, s2cost);
}
