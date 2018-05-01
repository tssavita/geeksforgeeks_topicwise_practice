#include <iostream>
#include <cstring>
#include <list>

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

        void DFSUtil(int v, int d, bool *visited, int *path, int path_index) {
            visited[v] = true;
            path[path_index] = v;
            path_index++;

            if (v == d) {
                for (int i = 0; i < path_index; i++) 
                    cout << path[i] << " ";
                cout << endl;
            }
            else {
                list<int>::iterator it;
                for (it = adjlist[v].begin(); it != adjlist[v].end(); it++) {
                    if ( !visited[*it] ) 
                        DFSUtil(*it, d, visited, path, path_index);
                    
                }
            }

            path_index--;
            visited[v] = false;
        }

        void printPaths(int s, int d) {
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            int *path = new int[vertices];
            int path_index = 0;

            DFSUtil(s, d, visited, path, path_index);
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v;

    Graph *g = new Graph(v);
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(0, 3);
    g->addEdge(2, 0);
    g->addEdge(2, 1);
    g->addEdge(1, 3);

    g->printPaths(2, 3);
}
