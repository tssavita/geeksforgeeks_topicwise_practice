#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    int vertices;
    int edges; 
    list< pair< pair<int, int>, int> > edges_list; 

    public:

    Graph() {}

    Graph(int vertex_number, int edge_number): vertices(vertex_number), edges(edge_number) {}

    void addEdge(int v1, int v2, int weight) {
        edges_list.push_back(make_pair(make_pair(v1, v2), weight));
    }

    bool isNegativeCycle() {
        vector<int> distance(vertices, INT_MAX);
        distance[0] = 0;

        for (int i = 0; i < vertices-1; i++) {
            list< pair< pair<int, int>, int> >::iterator it1;
            for (it1 = edges_list.begin(); it1 != edges_list.end(); it1++) {
                int u = it1->first.first;
                int v = it1->first.second;
                int weight = it1->second;
                if (distance[u] != INT_MAX && distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;    
                }
            }
        }

        for (int i = 0; i < vertices; i++)
            cout << distance[i] << " ";
        cout << endl;

        list< pair< pair<int, int>, int> >::iterator it2;
        for (it2 = edges_list.begin(); it2 != edges_list.end(); it2++) {
            int u = it2->first.first;
            int v = it2->first.second;
            int weight = it2->second; 
            if (distance[u] != INT_MAX && distance[v] > distance[u] + weight) {
                cout << u << distance[u] << " - " << v << distance[v];
                return true;
            }
        }
        return false; 
    }
};

int main(int argc, char ** argv) {
    int vertex_number, edge_number;

    cin>>vertex_number;
    cin>>edge_number;

    Graph *g = new Graph(vertex_number, edge_number);

    g->addEdge(0, 1, -1);
    g->addEdge(0, 2, 4);
    g->addEdge(1, 2, 3);
    g->addEdge(1, 3, 2);
    g->addEdge(1, 4, 2);
    g->addEdge(3, 2, 5);
    g->addEdge(3, 1, 1);
    g->addEdge(4, 3, -3);

    if (g->isNegativeCycle())
        cout << "Contains negative edge cycle" << endl;
    else 
        cout << "Does not contain negative edge cycle" << endl;

    Graph *g2 = new Graph(4, 4);

    g2->addEdge(0, 1, 1);
    g2->addEdge(1, 2, -1);
    g2->addEdge(2, 3, -1);
    g2->addEdge(3, 0, -1);

    if (g2->isNegativeCycle())
        cout << "Contains negative edge cycle" << endl;
    else 
        cout << "Does not contain negative edge cycle" << endl;

}
