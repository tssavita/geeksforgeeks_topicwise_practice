#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/* class DST {
    int id;
    DST *parent;

}*/

int find(vector<int>parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);

    return parent[x];
}

void Union(vector<int> parent, vector<int> rank, int x, int y) {
    int xSet = find(parent, x);
    int ySet = find(parent, y);

    if (rank[xSet] > rank[ySet])
        parent[xSet] = ySet;
    else if (rank[xSet] < rank[ySet])
        parent[ySet] = xSet;
    else {
        parent[xSet] = ySet;
        rank[ySet]++;
    }

}

class Graph {
    int vertices; 
    vector< pair<int, int> > edges;

    public:
    
    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
    }

    void addEdge(int src, int dest) {
        edges.push_back(make_pair<int,int>(src, dest));
    }
    bool isCycled() {
        vector<int> parent(-1);
        vector<int> rank(-1);
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i].first;
            int y = edges[i].second;

            if (x == y)
                return true;
            Union(parent,rank, x, y);
        }
        return false;
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
        cout << "Graph doesn't contain cycle";
}
