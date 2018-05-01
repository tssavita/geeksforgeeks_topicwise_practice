#include <iostream>
#include <climits>
#include <list>
#include <cstring>

using namespace std; 

class Graph {
    public:
        int vertices; 
        int **adjmatrix;

        Graph() {}

        Graph(int v): vertices(v)  {
            adjmatrix = new int*[vertices];
            for (int i = 0; i < vertices; i++)
                adjmatrix[i] = new int[vertices];
        }

        int minCost() {
            int dist[vertices]; 
            memset(dist, vertices, INT_MAX); 
            dist[0] = 0;
                
            for (int i = 0; i < vertices; i++) {
                for (int j = i + 1; j < vertices; j++) {
                    if (dist[j] > dist[i] + adjmatrix[i][j])
                        dist[j] = dist[i] + adjmatrix[i][j];
                }
            }

            return dist[vertices-1];
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
    cout << g->minCost();
}
