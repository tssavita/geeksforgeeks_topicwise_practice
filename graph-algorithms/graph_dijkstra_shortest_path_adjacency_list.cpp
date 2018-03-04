#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <climits>
#include <set>
#include <utility>

using namespace std;

class Graph {
    int vertices;
    list< pair<int, int> > *adjList;

    public:
    
    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        adjList = new list< pair<int, int> >[vertices];
    }

    void add_edge(int v1, int v2, int weight) {
        adjList[v1].push_back(make_pair(v2, weight));
        adjList[v2].push_back(make_pair(v1, weight));
    }

    void dijkstra_shortest_path(int src) {
        set< pair<int, int> > vertex_tracker;
        vector<int> distance(vertices, INT_MAX);

        distance[src] = 0;
        vertex_tracker.insert(make_pair(src, 0));

        while ( !vertex_tracker.empty() ) {
            pair <int, int> temp = *(vertex_tracker.begin());
            vertex_tracker.erase(vertex_tracker.begin());

            int u = temp.first;

            list< pair<int, int> >::iterator it;
            for (it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = (*it).first;
                int uv_weight = (*it).second;

                if (distance[v] > distance[u] + uv_weight) {

                    if (distance[v] != INT_MAX) {
                        set< pair<int, int> >::iterator found_at = vertex_tracker.find(make_pair(v, distance[v]));
                        if (found_at != vertex_tracker.end())
                            vertex_tracker.erase(vertex_tracker.find(make_pair(v, distance[v])));
                    }

                    distance[v] = distance[u] + uv_weight;
                    vertex_tracker.insert(make_pair(v, distance[v]));
                }
            }
        }

        for (int i = 0; i < vertices; i++) 
            cout << i << " - " << distance[i] << endl;
    }
};

int main(int argc, char ** argv) {
    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number); 

    g->add_edge(0, 1, 4);
    g->add_edge(0, 7, 8);
    g->add_edge(1, 2, 8);
    g->add_edge(1, 7, 11);
    g->add_edge(2, 3, 7);
    g->add_edge(2, 8, 2);
    g->add_edge(2, 5, 4);
    g->add_edge(3, 4, 9);
    g->add_edge(3, 5, 14);
    g->add_edge(4, 5, 10);
    g->add_edge(5, 6, 2);
    g->add_edge(6, 7, 1);
    g->add_edge(6, 8, 6);
    g->add_edge(7, 8, 7);

    g->dijkstra_shortest_path(0);
}
