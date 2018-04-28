#include <iostream>

using namespace std; 

bool available_positions(int n, int **board, int &row, int &col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0)
                return true;
        }
    }

    return false;
}

bool row_check(int row, int number, int n, int **challenge) {
    for (int i = 0; i < n; i++) {
        if (challenge[row][i] == number)
            return false;
    }
    return true;
}

bool col_check(int col, int number, int n, int **challenge) {
    for (int i = 0; i < n; i++) {
        if (challenge[i][col] == number)
            return false;
    }
    return true;
}

bool box_check(int row, int col, int number, int n, int **challenge) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (challenge[row + i][col + j] == number)
                return false; 
        }
    }
    return false; 
}

bool is_okay(int row, int col, int number, int n, int **challenge) {
    return ( !(row_check(row, number, n, challenge) && !(col_check(col, number, n, challenge) && !box_check(row, col, number, n, challenge) );
}

bool sudoku_util(int n, int **challenge) {
    if ( !available_positions(n, challenge) )
        return true;

    for (int num = 1; num <= 9; num++) {
        if ( is_okay(row, col, num, n, challenge) ) {
            challenge[row][col] = num;
            if (sudoku_util(n, challenge)) 
                return true;
            challenge[row][col] = 0;
        }
    }

    return false; 
}

bool sudoku(int n, int **challenge) {
    if (!sudoku_util(n, board))
        return false;

    print(challenge);
    return false; 
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) 
        arr[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++) 
            cin>>arr[i][j];
    }

    sudoku(n, arr);
}
