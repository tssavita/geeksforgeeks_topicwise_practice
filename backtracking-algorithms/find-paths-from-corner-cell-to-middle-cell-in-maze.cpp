#include <iostream>

using namespace std;

void path_to_middle(int **mat, int m, int n, int x, int y, int xmove, int ymove) {
    if (x == m/2 && y == n/2) 
        return;

    for (int i = 0; i < 4; i++) {
        if (is_okay(visited, next)) {
            visited.insert(next);
            path.push_back(next);
            path_to_middle(mat, m, n, xmove[i], ymove[i], xmove, ymove);
            path.pop_back();
            visited.erase(next);
        }
    }
}

void path_to_middle(int **mat, int m, int n) {
    int xmoves[] = {0, 1, 0, -1};
    int ymoves[] = {1, 0, -1, 0};

    int xstart[] = {0, 0, m, m};
    int ystart[] = {0, n, 0, n};

    list<pair<int, int> > path;
    set<pair<int, int> > visited;

    for (int i = 0; i < 4; i++) {
        int xnext = xstart[i];
        int ynext = ystart[i];

        path.push_back(make_pair(xnext, ynext));
        visited.insert(make_pair(xnext, ynext));

        path_to_middle_util(mat, m, n, xnext, ynext, path, visited, xmove, ymove); 

        path.pop_back();
        visited.erase(make_pair(xnext, ynext));
    }
}

int main(int argc, char ** argv) {
    int m, n;
    cin>>m>>n;
    
    int **mat = new int*[m];
    for (int i = 0; i < m; i++)
        mat[i] = new int[n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }

    path_to_middle(mat, m, n);
}
