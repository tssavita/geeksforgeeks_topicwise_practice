#include <iostream>

using namespace std;

int min_number_insertions(string s) {
    int cache[s.size()][s.size()];

    for (int i = 0; i < s.size(); i++)
        cache[i][i] = 1;

    for (int cl = 2; cl < s.size(); cl++) {
        for (int i = 0; i < (s.size()-cl+1); i++) {
            int j = i + cl - 1;
            if (s[i] == s[j] && cl == 2)
                cache[i][j] = 2;
            else if (s[i] == s[j])
                cache[i][j] = cache[i+1][j-1] + 2;
            else 
                cache[i][j] = max(cache[i+1][j], cache[i][j-1]);
        }
    }

    return cache[0][s.size()-1];
}

int min_number(string s) {
    return s.size() - min_number_insertions(s);
}

int main(int argc, char **argv) {
    string s; 
    getline(cin, s);

    cout << min_number(s);
}
