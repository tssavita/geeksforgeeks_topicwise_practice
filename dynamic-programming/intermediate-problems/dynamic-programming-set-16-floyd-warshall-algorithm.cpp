#include <iostream>
#include <climits>

using namespace std; 

void print(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == INT_MAX)
                cout << "INF" << " ";
            else 
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd_warshall(int **mat, int n) {
    int **temp = new int*[n];
    for (int i = 0; i < n; i++) 
        temp[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (temp[i][k] + temp[k][j] < mat[i][j] && temp[i][k] != INT_MAX && temp[k][j] != INT_MAX)
                    temp[i][j] = temp[i][k] + temp[k][j];
            }
        }
    }

    print(temp, n);
}

int main(int argc, char **argv) {
    int n; 
    cin>>n;
    int **mat = new int*[n];
    for (int i = 0; i < n; i++) 
        mat[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin>>mat[i][j];
    }

    floyd_warshall(mat, n);
}
