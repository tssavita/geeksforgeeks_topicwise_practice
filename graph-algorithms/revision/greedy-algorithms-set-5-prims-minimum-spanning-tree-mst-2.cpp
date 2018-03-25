#include <iostream> 
#include <cstdio>
#include <assert.h>
#include <climits>

using namespace std;

class Graph {
    public:
        int v;
        int ** adjmatrix;
        Graph() {}
        Graph(int v1, int **mat): v(v1) {
            adjmatrix = new int*[v];
            for (int i = 0; i < v; i++)
                adjmatrix[i] = new int[v];
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++)
                    adjmatrix[i][j] = mat[i][j];
            }
        }
};

int min(int *value, bool *included) {
    assert(sizeof(value) != 0);

    int valsize = sizeof(value) / sizeof(value[0]);

    int minval = INT_MAX, minindex = 0;
    for (int i = 0; i < valsize; i++) {
        if (minval > value[i] && !included[i]) 
            minval = value[i], minindex = i;
    }
    return minindex; 
}

void mst(Graph *g) {
    assert(sizeof(g) != 0);

    bool *included = new bool[g->v];
    int *parent = new int[g->v];
    int *value = new int[g->v];
    for (int i = 1; i < g->v; i++) {
        value[i] = INT_MAX;
        included[i] = false;
    }
    value[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < ((g->v)-1); i++) {
        int minv = min(value, included);
        included[minv] = true;
        for (int i = 0; i < g->v; i++) {
            if (g->adjmatrix[minv][i] && !included[i] && g->adjmatrix[minv][i] < value[i]) 
                value[i] = g->adjmatrix[minv][i], parent[i] = minv;
        }
    }

    for (int i = 1; i < g->v; i++)
        cout << parent[i] << " " << i << " " << g->adjmatrix[i][parent[i]] << endl;
}

int main(int argc, char ** argv) {
    int v; 
    cin>>v;

    int **mat = new int*[v];
    for (int i = 0; i < v; i++)
        mat[i] = new int[v];

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            cin>>mat[i][j];
    }

    Graph *g = new Graph(v, mat);
    
    mst(g); 
}
