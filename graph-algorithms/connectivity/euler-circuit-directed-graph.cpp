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
                for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) 
                    r->adjlist[*it].push_back(i);
            }

            return r;
        }

        void DFSUtil(int i, bool *visited) {
            visited[i] = true;

            list<int>::iterator it;
            for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                if ( !visited[*it] )
                    DFSUtil(*it, visited);
            }
        }

        bool isEulerCircuit() {
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            int j;
            for (j = 0; j < vertices; j++) {
                if (adjlist[j].size() > 0)
                    break;
            }

            DFSUtil(j, visited);

            for (int i = 0; i < vertices; i++)  {
                if ( !visited[i] && adjlist[i].size() > 0 )
                    return false; 
            }

            Graph *rev = transpose();

            memset(visited, false, vertices);

            rev->DFSUtil(j, visited);

            for (int i = 0; i < vertices; i++) {
                if ( !visited[i] && adjlist[i].size() > 0 )
                    return false; 
            }

            return true; 
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v;

    Graph *g = new Graph(v);
    g->addEdge(1, 0);
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(0, 3);
    g->addEdge(3, 4);
    g->addEdge(4, 0);

    cout << g->isEulerCircuit();    
}
