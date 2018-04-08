#include <iostream>
#include <climits> 
#include <vector>

using namespace std; 

class edge {
    public:
        int src; 
        int dest; 
        int weight;
        edge() {}
        edge(int s, int d, int w): src(s), dest(d), weight(w) {}
};

class graph {
    public:
        int v;
        int e;
        vector<edge> edges; 
        graph() {}
        graph(int v1, int e1): v(v1), e(e1) {}

        void print(int dist[]);
        void bellman_ford();
};

void graph::print(int dist[]) {
    for (int i = 0; i < v; i++) 
        cout << i << " " << dist[i] << " ";
    cout << endl;
}

void graph::bellman_ford() {
    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            edge temp = edges[j];
            int u = temp.src;
            int v = temp.dest; 
            int wght = temp.weight;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + wght) {
                dist[v] = dist[u] + wght;
            }
        }
    }
    for (int i = 0; i < e; i++) {
        edge temp = edges[i];
        int u = temp.src;
        int v = temp.dest; 
        int wght = temp.weight;
        if (dist[u] != INT_MAX && dist[v] > dist[u] + wght) 
            cout << "negative cycle";
    }

    print(dist);
}

int main(int argc, char **argv) {
    int v, e;
    cin>>v>>e;
    graph *g = new graph(v, e);
    for (int i = 0; i < e; i++) {
        int ts, td, tw;
        cin>>ts>>td>>tw;
        edge te(ts, td, tw);
        g->edges.push_back(te);
    }

    g->bellman_ford();
}
