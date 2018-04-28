#include <iostream>

using namespace std; 

int count(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int cache[m+1][n+1];
    for (int i = 1; i <= n; i++)
        cache[0][i] = 0;

    for (int i = 1; i <= n; i++) 
        cache[i][0] = 1;


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                cache[i][j] = cache[i-1][j-1] + cache[i-1][j];
            else 
                cache[i][j] = cache[i-1][j];
        }
    }

    return cache[m+1][n+1];
}

int main(int argc, char ** argv) {
    string s1, s2; 
    getline(cin, s1);
    getline(cin, s2);

    cout << count(s1, s2);
}
