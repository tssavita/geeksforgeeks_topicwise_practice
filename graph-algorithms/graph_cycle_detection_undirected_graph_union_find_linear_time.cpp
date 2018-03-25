#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Graph {
    int vertices;
    int *parents;
    vector<pair<int, int> > edges;

    public:

    Graph() {}
    
    Graph(int vertex_number): vertices(vertex_number) {
        parents = new int[vertices];
        for (int i = 0; i < vertices; i++)
            parents[i] = -1;
    }

    void addEdge(int src, int dest) {
        edges.push_back(pair<int, int>(src,dest));
    }

    int find(int x) {
        if (parents[x] == -1)
            return x;
        return find(parents[x]);
    }

    void Union(int x, int y) {
        int xset = find(x);
        int yset = find(y);

        parents[xset] = yset;
    }

    bool isCycled() {
        for (int i = 0; i < edges.size(); i++) {
            int x = find(edges[i].first);
            int y = find(edges[i].second);

            if (x == y)
                return true;

            Union(x, y);
        }
        return false;
    }
    
    void print() {
        for (int i = 0; i < vertices; i++)
            cout << parents[i] << " ";
        cout << endl;
    }

};

int main(int argc, char ** argv) {

    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number);
    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(2, 0);

    if (g->isCycled())
        cout << "Graph contains cycle";
    else 
        cout << "Graph does not contain cycle";
}
