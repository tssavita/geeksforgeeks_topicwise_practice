#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class Edge {
    public:
        int source;
        int destination;
        Edge() {}
        Edge(int s, int d): source(s), destination(d) {}
};

int find(int *parents, int x) {
    if (parents[x] == -1)
        return x;

    return find(parents, parents[x]);
}

void unionds(int *parents, int x, int y) {
    int xp = find(parents, x);
    int yp = find(parents, y);
    parents[xp] = yp;
}

class Graph {
    public:
        int v;
        int e;
        vector<Edge> edges;
        Graph(int v_num, int e_num): v(v_num), e(e_num) {}

        bool isCyclic() {
            int *parents = new int[v];
            for (int i = 0; i < v; i++)
                parents[i] = -1;

            for (int i = 0; i < edges.size(); i++) {
                int x = find(parents, edges[i].source);
                int y = find(parents, edges[i].destination);
                
                if (x == y)
                    return true; 
                unionds(parents, x, y);
            }
            return false; 
        }
};

int main(int argv, char ** argc) {
    int vertices, edges;
    cin>>vertices>>edges;

    Graph *g = new Graph(vertices, edges);

    for (int i = 0; i < edges; i++) {
        int s1, d1;
        cin>>s1>>d1;
        Edge temp(s1, d1);
        g->edges.push_back(temp);
    }

    cout << g->isCyclic();
}
