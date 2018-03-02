#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int find(int *parent, int x);
void Union(int *parent, int x, int y);

class Graph {
    int vertices;
    vector< pair<int, int> > edges;

    public:

    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {}

    void addEdge(int src, int dest) {
        edges.push_back(make_pair<int, int>(src, dest));
    }

    bool isCycled() {
        int *parents = new int[vertices];

        for (int i = 0; i < vertices; i++)
            parents[i] = -1;

        for (int i = 0; i < edges.size(); i++) {
            int x = find(parents, edges[i].first);
            int y = find(parents, edges[i].second);

            if (x == y)
                return true;
            
            Union(parents, x, y);
        }
    }
};

int find(int *parent, int x) {
    if (parent[x] == -1)
        return x;
    return find(parent, parent[x]);
}

void Union(int *parent, int x, int y) {
    int xSet = find(parent, x);
    int ySet = find(parent, y);

    parent[xSet] = ySet;
}

int main(int argc, char ** argv) {
    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number);
    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(2, 0);

    if (g->isCycled())
        cout << "Graph is cycled";
    else 
        cout << "Graph is not cycled";
}
