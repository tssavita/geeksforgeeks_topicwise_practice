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
            adjlist[v].push_back(u);
        }

        void DFSUtil(int i, bool *visited) {
            visited[i] = true; 

            list<int>::iterator it; 
            for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                if ( !visited[*it] )
                    DFSUtil(*it, visited);
            }
        }

        bool isConnected() {
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            int i;
            // Finding a vertex starting point, that has a non-zero degree
            for (i = 0; i < vertices; i++) {
                if (adjlist[i].size() != 0)
                    break;
            }

            if (i == vertices) 
                return true; 

            DFSUtil(i, visited); 

            for (i = 0; i < vertices; i++) {
                if (visited[i] == false && adjlist[i].size() > 0) {
                    cout << "Here";
                    return false;
                }
            }

            return true; 
        }

        int isEulerian() {
            if (isConnected() == false)
                return 0;

            cout << "coming here";

            int odd_degree = 0;
            for (int i = 0; i < vertices; i++) {
                if (adjlist[i].size() & 1) 
                    odd_degree++;
            }
            
            if (odd_degree > 2)
                return 0;

            return (odd_degree) ? 1 : 2;
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
    (g->isEulerian() == 0) ? cout << "Not Eulerian" : (g->isEulerian() == 1) ? cout << "Eulerian Cycle" : cout << "Eulerian Path";

    Graph *g1 = new Graph(v);
    g1->addEdge(1, 0);
    g1->addEdge(0, 2);
    g1->addEdge(2, 1);
    g1->addEdge(0, 3);
    g1->addEdge(3, 4);
    g1->addEdge(4, 0);

    (g1->isEulerian() == 0) ? cout << "Not Eulerian" : (g1->isEulerian() == 1) ? cout << "Eulerian Cycle" : cout << "Eulerian Path";
}

