#include <iostream>
#include <list> 
#include <vector>
#include <utility>
#include <stdlib.h>
#include <stdio.h>
#include <climits>

using namespace std;

class Graph {
    int vertices;
    int edges;
    list< pair<pair<int, int>, int> > edges_list;

    public:

    Graph() {}

    Graph(int vertex_number, int edge_number): vertices(vertex_number), edges(edge_number) {
    }

    void add_edge(int v1, int v2, int weight) { 
        edges_list.push_back(make_pair(make_pair(v1, v2), weight));
    }

    void shortest_path(int src) {

        vector<int> distance(vertices, INT_MAX);

        distance[src] = 0;

        for (int i = 0; i < vertices-1; i++) {
            list < pair <pair<int, int>, int> >::iterator it = edges_list.begin();
            for (; it != edges_list.end(); it++) {
 
                int u = it->first.first;
                int v = it->first.second;
                int weight = it->second;

                if (distance[u] != INT_MAX && distance[v] > distance[u] + weight) 
                    distance[v] = distance[u] + weight;
            }
        }
        for (int i = 0; i < vertices; i++)
            cout << i << " " << distance[i] << endl;
    }
};

int main(int argc, char ** argv) {
    int edge_number;
    cin>>edge_number;
    Graph *g = new Graph(5, edge_number);

    g->add_edge(0, 1, -1);
    g->add_edge(0, 2, 4);
    g->add_edge(1, 2, 3);
    g->add_edge(1, 3, 2);
    g->add_edge(1, 4, 2);
    g->add_edge(3, 2, 5);
    g->add_edge(3, 1, 1);
    g->add_edge(4, 3, -3);

    g->shortest_path(0);
}
