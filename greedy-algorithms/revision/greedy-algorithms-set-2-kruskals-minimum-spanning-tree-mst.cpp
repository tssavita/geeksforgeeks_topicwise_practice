#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class edge {
    public:
        int source;
        int dest;
        int weight;
        edge(int s, int d, int w): source(s), dest(d), weight(w) {}
};

class ds {
    public:
        int parent;
        int rank;
        ds find(ds *subsets, ds x) {
            if (subsets[x].parent == x)
                return subsets[x].parent;
            return find(subsets, subsets[x].parent);
        }
        void unionds(ds x, ds y) {
            if (x.rank > y.rank) {
                y.parent = x; 
                x.rank++;
            }
            else {
                x.parent = y;
                y.rank++;
            }
        }
};


class graph {
    public:
        int vertex_num;
        int edge_num;
        vector<edge> edges;
        graph(int v, int e): vertex_num(v), edge_num(e) {}
}

void mst(graph *g) {

    int *subsets = new int[g->vertex_num - 1];
    for (int j = 0; j < vertex_num; j++) 

    sort(g->edges.begin(), g->edges.end());
    int e = 0, i = 0;

    edge order[];
    int k = 0;

    while ( e < g->vertex_num - 1) {
        edge next_edge = g->edges[i++];
        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            order[k++] = edge;
            unionds(subsets, x, y);
        }
    }
}

int main(int argc, char ** argv) {
    int v, e;
    cin>>v>>e;

    graph *g = new graph(v, e);
    vector<edge> edges;
    for (int i = 0; i < n; i++) {
        int s, d, w;
        cin>>s, d, w;
        edge temp(s, d, w);
        g->edges.push_back(temp);
    }
    
    mst(g);
}
