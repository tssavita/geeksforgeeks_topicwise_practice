#include <iostream>

using namespace std; 

bool is_okay(int v, int pathi, int *path, int **adjmatrix) {
    if ( !adjmatrix[path[pathi - 1]][v] )
            return false;

    for (int i = 0; i < pathi; i++)
        if (path[i] == v)
            return false;
    return true;
}

void print(int v, int *path) {
    for (int i = 0; i < v; i++) 
        cout << path[i] << " ";
    cout << path[0];
    cout << endl;
}

bool hamiltonian_cycle_util(int v, int pathi, int *path, int **adjmatrix) {
    if (pathi == v) {
        if (adjmatrix[0][path[pathi - 1]])
            return true;
        else 
            return false;
    }

    for (int i = 1; i < v; i++) {
        if ( is_okay(i, pathi, path, adjmatrix) ) {
            path[pathi] = i;
            if ( hamiltonian_cycle_util(v, pathi + 1, path, adjmatrix) )
                return true;
            path[pathi] = -1;
        }
    }
    return false;
}

bool hamiltonian_cycle(int v, int **adjmatrix) {
    int *path = new int[v];
    for (int i = 0; i < v; i++)
        path[i] = -1;

    path[0] = 0;
    if ( !hamiltonian_cycle_util(v, 1, path, adjmatrix) )
        return false;

    print(v, path);
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

    hamiltonian_cycle(v, adjmatrix);
}
