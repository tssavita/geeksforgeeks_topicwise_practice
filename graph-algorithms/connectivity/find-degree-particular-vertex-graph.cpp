#include <iostream>

using namespace std; 

class Graph {
    public:
        int vertices;
        int **adjmatrix;

        Graph() {}

        Graph(int v): vertices(v) {
            adjmatrix = new int*[vertices];
            for (int i = 0; i < vertices; i++) 
                adjmatrix[i] = new int[vertices];
        }

        int degree(int v) {
            int d = 0;
            for (int i = 0; i < vertices; i++) {
                if (adjmatrix[v][i] == 1 && v != i)
                    d++;
            }

            return d;
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v;

    Graph *g = new Graph(v);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) 
            cin>>g->adjmatrix[i][j];
    }

    int v1;
    cin>>v1;
    cout << g->degree(v1);
}
