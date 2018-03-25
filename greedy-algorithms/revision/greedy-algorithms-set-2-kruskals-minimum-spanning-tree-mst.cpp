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
        int find(ds *subsets, int x) {
            if (subsets[x].parent == x)
                return subsets[x].parent;
            return find(subsets, subsets[x].parent);
        }
        void unionds(ds *subsets, int x1, int y1) {
            int x = find(subsets, x1);
            int y = find(subsets, y1);
            if (subsets[x].rank > subsets[y].rank) {
                subsets[y].parent = x; 
                subsets[x].rank++;
            }
            else {
                subsets[x].parent = y;
                subsets[y].rank++;
            }
        }
};


class graph {
    public:
        int vertex_num;
        int edge_num;
        vector<edge> edges;
        graph(int v, int e): vertex_num(v), edge_num(e) {}
};

void mst(graph *g) {

    sort(g->edges.begin(), g->edges.end());
    int e = 0, i = 0;

    vector<edge> order;
    int k = 0;

    ds *subsets = new ds[g->vertex_num];
    for (int i = 0; i < g->vertex_num; i++) {
        subsets[i].rank = 0;
        subsets[i].parent = i;
    }

    for (int e = 0; e < (g->vertex_num - 1); e++)
        edge next_edge = g->edges[i++];
        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            order.push_back(edge);
            unionds(subsets, x, y);
        }
    }
    for (int j = 0; j < k; j++) 
        cout << order[j].source << " " << order[j].weight << " " << order[j].dest << endl;
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
