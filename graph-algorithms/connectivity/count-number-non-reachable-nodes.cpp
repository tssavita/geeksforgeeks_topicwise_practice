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

        void DFSUtil(int v, bool *visited) {
            visited[v] = true; 

            list<int>::iterator it;
            for (it = adjlist[v].begin(); it != adjlist[v].end(); it++) {
                if ( !visited[*it] ) 
                    DFSUtil(*it, visited);
            }
        }

        int nodesUnreachable(int head) {
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            DFSUtil(head, visited); 
            
            int count = 0;
            for (int i = 0; i < vertices; i++) {
                if (visited[i] == false)
                    count++;
            }

            return count;
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v;
    
    Graph *g = new Graph(v); 
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(3, 4);
    g->addEdge(4, 5);
    g->addEdge(6, 7);

    cout << g->nodesUnreachable(2);
}
