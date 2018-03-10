#include <iostream>

using namespace std;

int min(int a, int b) {
    return a ^ ((a ^ b) & -(a < b));
}

int min1(int a, int b) {
    if (a < b)
        return a;
    else 
        return b;
}

void sub_matrix_ones(int matrix[6][6], int rows, int columns) {
    int submatrix[rows][columns];
    
    for (int i = 0; i < rows; i++)
        submatrix[i][0] = matrix[i][0];

    for (int i = 0; i < columns; i++)
        submatrix[0][i] = matrix[0][i];

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            if (matrix[i][j] == 1)
                submatrix[i][j] = min1(min1(submatrix[i-1][j], submatrix[i][j-1]), submatrix[i-1][j-1]) + 1; 
            else 
                submatrix[i][j] = 0;
        }
    }

    int max = submatrix[0][0], i_max = 0, j_max = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns;j++) {
            if (max < submatrix[i][j]) {
                max = submatrix[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }

    for (int i = i_max; i > i_max - max; i--) {
        for (int j = j_max; j > j_max - max; j--) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char ** argv) {
    int rows = 6;
    int columns = 6;
    int matrix[6][6] =  {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};
    sub_matrix_ones(matrix, rows, columns);
}
