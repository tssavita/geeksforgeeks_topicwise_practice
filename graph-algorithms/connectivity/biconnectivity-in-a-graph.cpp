#include <iostream>
#include <climits>
#include <list>
#include <cstring>

using namespace std; 

class Graph {
    public: 
        int vertices;
        list<int> *adjlist;
        
        Graph() {}
        
        Graph(int v): vertices(v) {
            adjlist = new list<int>[vertices];
        }
        
        void addEdge(int u, int v) {
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        bool isBCUtil(int u, bool *visited, int *low, int *parent, int *disc) {
            static int time = 0;
            int children = 0;
            visited[u] = true; 
            disc[u] = low[u] = ++time;
            
            list<int>::iterator it;
            for (it = adjlist[u].begin(); it != adjlist[u].end(); it++) {
                int v = *it;
                if ( !visited[v] ) {
                    children++;
                    parent[v] = u;

                    if (isBCUtil(v, visited, low, parent, disc))
                        return true;

                    low[u] = min(low[u], low[v]);

                    if (parent[u] == INT_MAX && children > 1) 
                        return true;
                    if (parent[u] != INT_MAX && low[v] >= disc[u])
                        return true; 
                }
                else if (v != parent[u])
                    low[u] = min(low[u], disc[v]);
            }
        }

        bool isBiconnected() {
            bool *visited = new bool[vertices];
            int *disc = new int[vertices];
            int *low = new int[vertices];
            int *parent = new int[vertices];

            memset(visited, false, vertices);
            memset(parent, INT_MAX, vertices);

            if (isBCUtil(0, visited, low, parent, disc) == true)
                return true; 
            
            for (int i = 0; i < vertices; i++) {
                if (visited[i] == false)
                    return false;
            }

            return true; 
        }
};

int main(int argc, char ** argv) {
    int v; 
    cin>>v; 

    Graph *g = new Graph(v);
    g->addEdge(0, 1);
    g->isBiconnected() ? cout << "biconnected" : cout << "not biconnected";
    
    g->addEdge(1, 0);
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(0, 3);
    g->addEdge(3, 4);
    g->addEdge(2, 4);
    g->isBiconnected() ? cout << "Yes" : cout << "No";
}
