#include <iostream>
#include <list>
#include <cstring>
#include <utility>

using namespace std; 

class Graph {
    public:
        int vertices; 
        list< pair<int, int> > *adjlist;

        Graph() {}

        Graph(int v): vertices(v) {
            adjlist = new list< pair<int, int> >[vertices];
        }

        void addEdge(int u, int v, int w) {
            adjlist[u].push_back(make_pair(v, w));
            adjlist[v].push_back(make_pair(u, w));
        }
            
        bool DFSUtil(int src, int k, bool *visited) {
            if (k <= 0)
                return true;

            list< pair<int, int> >::iterator it;
            for (it = adjlist[src].begin(); it != adjlist[src].end(); it++) {
                int v = (*it).first;
                int w = (*it).second;
                
                if (visited[v])
                    continue;

                if (w >= k)
                    return true; 

                visited[v] = true; 
                if (DFSUtil(v, k - w, visited))
                    return true;
                visited[v] = false;
            }

            return false;
        }

        bool pathGreaterThank(int src, int k) {
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            visited[src] = true; 

            DFSUtil(src, k, visited);
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v; 
    
    Graph *g = new Graph(v);

    g->addEdge(0, 1, 4);
    g->addEdge(0, 7, 8);
    g->addEdge(1, 2, 8);
    g->addEdge(1, 7, 11);
    g->addEdge(2, 3, 7);
    g->addEdge(2, 8, 2);
    g->addEdge(2, 5, 4);
    g->addEdge(3, 4, 9);
    g->addEdge(3, 5, 14);
    g->addEdge(4, 5, 10);
    g->addEdge(5, 6, 2);
    g->addEdge(6, 7, 1);
    g->addEdge(6, 8, 6);
    g->addEdge(7, 8, 7);

    int k, src;
    cin>>k>>src;
    cout << g->pathGreaterThank(src, k);
}
