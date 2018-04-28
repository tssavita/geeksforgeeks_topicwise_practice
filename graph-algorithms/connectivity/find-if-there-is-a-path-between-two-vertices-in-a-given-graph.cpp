#include <iostream>
#include <queue>
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
        bool isReachable(int s, int d) {
            if (s == d) 
                return true; 
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            list<int> q;
            visited[s] = true;
            q.push_back(s);
            
            while ( !q.empty() ) {
                s = q.front();
                q.pop_front();
                list<int>::iterator *it;
                for (it = adjlist[s].begin(); it != adjlist[s].end(); it++) {
                    if (*it == d)
                        return true; 
                    if ( !visited[*it] ) {
                        visited[*it] = true; 
                        q.push_back(*it);
                    }
                }
            }

            return false;
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v;
    
    Graph *g = new Graph(v);

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 3);
    cout << g->isReachable(0, 4); 
}
