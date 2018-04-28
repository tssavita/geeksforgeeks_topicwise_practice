#include <iostream>

using namespace std;

void print(int **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool is_okay(int **board, int n, int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--,  j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool queen_util(int **board, int n, int col) {
    if (col == n) {
        print(board, n);
        return true;
    }

    bool res = false; 
    for (int i = 0; i < n; i++) {
        if (is_okay(board, n, i, col)) {
            board[i][col] = 1;
            res = queen_util(board, n, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void queen(int n) {
    int **board = new int*[n];
    for (int i = 0; i < n; i++)
        board[i] = new int[n];

    if (!queen_util(board, n, 0))
        cout << "No solution";
        
    return;
}

int main(int argc, char **argv) {
    int n;
    cin>>n;

    queen(n);
}
