#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int min(int a, int b) {
    return (a < b)? a : b;
}

int search(int arr[], int low, int high, int n) {
    int mid = (low + high) / 2;
    
    if (low <= high) {
        if (n > arr[mid])
            return search(arr, mid + 1, high, n);
        return search(arr, low, mid - 1, n);
    }
    return low;
}

int min_abs_diff(int **mat, int rows, int columns) {

    for (int i = 0; i < rows; i++) 
        sort(mat[i], mat[i] + columns);

    int min_diff = INT_MAX;
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < columns; j++) {
            int p = search(mat[i + 1], 0, columns - 1, mat[i][j]);
            min_diff = min(abs(mat[i + 1][p] - mat[i][j]), min_diff);
            if (p - 1 >= 0)
                min_diff = min(abs(mat[i + 1][p - 1] - mat[i][j]), min_diff);
        }
    }
    return min_diff;
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

    cout << min_abs_diff(mat, rows, columns);
}
