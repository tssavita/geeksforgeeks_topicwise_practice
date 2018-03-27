#include <iostream>
#include <vector>

using namespace std; 

void print(vector<int> path) {
    for (int i = 0; i < path.size(); i++) 
        cout << path[i] << " ";
}

void solve_paths_util(int **mat, int row, int ri, int column, int ci, vector< vector<int> > paths, int pathi) {
    if (ri == row - 1) {
        for (int i = ci; i < column; i++) {
            paths[pathi].push_back(mat[row][i]);
        }
        print(paths[pathi]);
        return;
    }
    if (ci == column - 1) {
        for (int j = ri; j < row; j++) {
            paths[pathi].push_back(mat[j][column]);
        }
        print(paths[pathi]);
        return;
    }

    paths[pathi].push_back(mat[ri][ci]);
    solve_paths_util(mat, row, ri + 1, column, ci, paths, pathi + 1);
    solve_paths_util(mat, row, ri, column, ci + 1, paths, pathi + 1);
}

int main(int argc, char ** argv) {
    int row, column;
    cin>>row>>column;

    int **mat = new int*[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new int[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin>>mat[i][j];
        }
    }

    vector< vector<int> > paths;
    solve_paths_util(mat, row, 0, column, 0, paths, 0);
}
