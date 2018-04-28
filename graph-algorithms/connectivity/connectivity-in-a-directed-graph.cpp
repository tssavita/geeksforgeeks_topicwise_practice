#include <iostream>
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
        }
        
        Graph *transpose() {
            Graph *r = new Graph(vertices);
            for (int i = 0; i < vertices; i++) {
                list<int>::iterator it; 
                for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                    r->adjlist[*it].push_back(i);
                }
            }
            return r;
        }

        void DFSUtil(int s, bool *visited) {
            visited[s] = true; 
            
            list<int>::iterator it; 
            for (it = adjlist[s].begin(); it != adjlist[s].end(); it++) {
                if ( !visited[*it] )
                    DFSUtil(*it, visited);
            }
        }

        bool isSC() {
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            DFSUtil(0, visited);
            for (int i = 0; i < vertices; i++) {
                if ( !visited[i] ) 
                    return false; 
            }

            memset(visited, false, vertices);

            Graph *r = transpose();
            r->DFSUtil(0, visited);
            for (int i = 0; i < r->vertices; i++) {
                if ( !visited[i])
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
    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 0);
    g->addEdge(2, 4);
    g->addEdge(4, 2);
    cout << g->isSC();

    Graph *g1 = new Graph(4);
    g1->addEdge(0, 1);
    g1->addEdge(1, 2);
    g1->addEdge(2, 3);
    cout << g1->isSC();
}
