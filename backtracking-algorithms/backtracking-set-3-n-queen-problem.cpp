#include <iostream>

using namespace std; 

void print(int n, int ** solution) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << solution[i][j] << " ";
        cout << endl;
    }
}

bool is_okay(int n, int row, int col, int ** solution) {
    for (int i = 0; i < col; i++) {
        if (solution[row][i])
            return false; 
    }

    for (int i = row, j = col; i >= 0 && j>= 0; i--, j--) {
        if (solution[i][j])
            return false;
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (solution[i][j])
            return false;
    }

    return true;
}

bool nqueens_util(int n, int col, int ** solution) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (is_okay(n, i, col, solution)) {
            solution[i][col] = 1; 
            if (nqueens_util(n, col + 1, solution))
                return true;
            solution[i][col] = 0;
        }
    }

    return false;
}

bool nqueens(int n) {
    int ** solution = new int*[n];
    for (int i = 0; i < n; i++)
        solution[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            solution[i][j] = 0;
    }

    if ( !nqueens_util(n, 0, solution) )
        return false;

    print(n, solution);
    return true;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    nqueens(n);
}
