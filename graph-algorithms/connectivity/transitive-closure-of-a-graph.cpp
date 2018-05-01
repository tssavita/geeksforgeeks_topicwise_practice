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

        void reachability() {
            int **reach; 
            reach = new int*[vertices];
            for (int i = 0; i < vertices; i++) 
                reach[i] = new int[vertices];

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) 
                    reach[i][j] = adjmatrix[i][j];
            }

            for (int k = 0; k < vertices; k++) {
                for (int i = 0; i < vertices; i++) {
                    for (int j = 0; j < vertices; j++) 
                        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                }
            }

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) 
                    cout << reach[i][j] << " ";
                cout << endl;
            }
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

    g->reachability();
}
