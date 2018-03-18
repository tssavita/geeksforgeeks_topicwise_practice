#include <iostream>

using namespace std;

int max_in_col(int **mat, int rows, int mid, int max_val) {
    int max_index = 0;
    for (int i = 0; i < rows; i++) {
        if (mat[i][mid] > max_val) {
            max_index = i;
            max_val = mat[i][mid];
        }
    }
    return max_index;
}

int peak(int **mat, int rows, int columns, int mid) {
    int max_val = 0;
    int max_index = max_in_col(mat, rows, mid, max_val);
    if (mid == 0 || mid == columns)
        return max_val;
    else if (max_val >= mat[max_index][mid - 1] || max_val >= mat[max_index][mid + 1])
        return max_val;
    else if (max_val < mat[max_index][mid])
        return peak(mat, rows, columns, mid - mid / 2);
    else 
        return peak(mat, rows, columns, mid + mid / 2);
}

int peak(int ** mat, int rows, int columns) {
    return peak(mat, rows, columns, columns / 2);
}

int main(int argc, char ** argv) {
    int rows, columns;
    cin>>rows>>columns;

    int **mat = new int*[rows];
    for (int i = 0; i < rows; i++) 
        mat[i] = new int[columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin>>mat[i][j];
        }
    }

    cout << peak(mat, rows, columns);
}
