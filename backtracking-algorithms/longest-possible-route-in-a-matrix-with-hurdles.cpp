#include <iostream>
#include <climits>

using namespace std;

class Pair {
    public:
        bool found;
        int value;
        Pair(bool f, int v): found(f), value(v) {}
};

Pair longest_route(int **mat, int x, int y, int r, int c, bool **visited) {
    if (x == r || c == y) {
        Pair p(true, 0);
        return p; 
    }

    if (x < 0 || x >= r || y < 0 || y >= c || !visited[x][y] || mat[x][y] == 0) {
        Pair p(false, INT_MAX);
        return p;
    }
    
    visited[x][y] = true;

    int res = INT_MIN;
    Pair sol = longest_route(mat, x, y - 1, r, c, visited);
    if (sol.found)
        res = max(res, sol.value);

    sol = longest_route(mat, x - 1, y, r, c, visited);
    if (sol.found)
        res = max(res, sol.value);

    sol = longest_route(mat, x, y + 1, r, c, visited);
    if (sol.found)
        res = max(res, sol.value);

    sol = longest_route(mat, x + 1, y, r, c, visited);
    if (sol.found)
        res = max(res, sol.value);

    visited[x][y] = false; 

    if (res != INT_MAX) {
        Pair p(true, 1 + res);
        return p;
    }
    else {
        Pair p(false, INT_MAX);
        return p;
    }
}

bool longest_route(int **mat, int r, int c) {
    bool **visited = new bool*[r];
    for (int i = 0; i < r; i++)
        visited[i] = new bool[c];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            visited[i][j] = false; 

    Pair p = longest_route(mat, 0, 0, r, c, visited);
    if (p.found)
        cout <<p.value << " ";
    else 
        cout << "not found"; 
}

int main(int argc, char ** argv) {
    int r, c;
    cin>>r>>c;

    int **mat = new int*[r];
    for (int i = 0; i < r; i++)
        mat[i] = new int[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cin>>mat[i][j];
    }

    longest_route(mat, r, c);
}
