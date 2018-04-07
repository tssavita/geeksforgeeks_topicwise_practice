#include <iostream>

using namespace std; 

int scs(string x, string y) {
    int cache[x.size() + 1][y.size() + 1];

    for (int i = 0; i <= x.size(); i++) {
        for (int j = 0; j <= y.size(); j++) {
            if ( !i )
                cache[i][j] = j;
            else if ( !j )
                cache[i][j] = i;
            else if (x[i-1] == y[j-1])
                cache[i][j] = 1 + cache[i-1][j-1];
            else 
                cache[i][j] = 1 + min(cache[i-1][j], cache[i][j-1]);
        }
    }

    return cache[x.size()][y.size()];
}

int main(int argc, char ** argv) {
    string x = "AGGTAB";
    string y = "GXTXAYB";

    cout << scs(x, y);
}
