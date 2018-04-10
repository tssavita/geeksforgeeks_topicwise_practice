#include <iostream>

using namespace std;

int zz_mat(int **mat, int n, int i, int j) {
    if (i == n-1)
        return mat[i][j];
    int zz = 0;
    for (int k = 0; k < n; k++) {
        if (k != j)
            zz = max(zz, zz_mat(mat, n, i+1, k));
    }

    return zz + mat[i][j];
}

int zz_mat(int **mat, int n) {
    int result = 0;
    for (int j = 0; j < n; j++)
        result = max(result, zz_mat(mat, n, 0, j));

    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int ** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>arr[i][j];
    }

    cout << zz_mat(arr, n);
}
