#include <iostream>

using namespace std; 

int make_palindrome(string s, int i, int j) {
    int cache[s.size()][s.size()];
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) 
            cache[i][j] = 0;
    }

    for (int space = 1; space < s.size(); space++) {
        for (int i = 0, j = space; j < s.size(); i++, j++) {
            cache[i][j] = (s[i] == s[j]) ? cache[i+1][j-1] : 
                ( min(cache[i][j-1], cache[i+1][j]) + 1);
        }
    }

    return cache[0][s.size()-1];
}

int main(int argc, char **argv) {
    string s;
    getline(cin, s);

    cout << make_palindrome(s, 0, s.size()-1);
}
