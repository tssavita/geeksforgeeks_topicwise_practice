#include <iostream>

using namespace std;

bool is_okay(int vi, int v, int c, int *color, int **adjmatrix) {
    for (int i = 0; i < v; i++) {
        if (adjmatrix[vi][i] && color[i] == c)
            return false;
    }
    return true;
}

void print(int *color, int v) {
    for (int i = 0; i < v; i++) 
        cout << i << " " << color[i] << " " << endl;
}

bool coloring_util(int vi, int v, int m, int *color, int **adjmatrix) {
    if (vi == v)
        return true;

    for (int i = 0; i < m; i++) {
        if ( is_okay(vi, v, i, color, adjmatrix) ) {
            color[vi] = i;
            if (coloring_util(vi + 1, v, m, color, adjmatrix))
                return true;
            color[vi] = 0;
        }
    }
    return false; 
}

bool coloring(int v, int m, int ** adjmatrix) {
    int *color = new int[v];
    for (int i = 0; i < v; i++)
        color[i] = -1;
    if ( !coloring_util(0, v, m, color, adjmatrix) )
        return false;

    print(color, v);
    return true;
}

int main(int argc, char ** argv) {
    int v;
    cin>>v;

    int **adjmatrix = new int*[v];
    for (int i = 0; i < v; i++) 
        adjmatrix[i] = new int[v];

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) 
            cin>>adjmatrix[i][j];
    }

    int m;
    cin>>m;

    cout << coloring(v, m, adjmatrix);
}
